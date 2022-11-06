import java.io.*;
import java.text.*;
import java.util.*;
public class D {
	public static void main(String[] args) throws Exception {
		new D().run();
	}
	public void run() throws Exception {
		BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(f.readLine());
		int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken())+1;
		if(m < n * 2) {
			System.out.println(-1);
			return;
		}
		PriorityQueue<Flight> arrive = new PriorityQueue<Flight>();
		ArrayList<Flight>[] depart = (ArrayList<Flight>[])new ArrayList[n];
		for(int i = 0; i < n; i++) depart[i] = new ArrayList<Flight>();
		for(int i =0 ; i < m; i++) {
			Flight fl = new Flight(f.readLine());
			if(fl.to)
				arrive.add(fl);
			else {
				depart[fl.city].add(fl);
				continue;
			}
		}
		int[][] min = new int[n][];
		int[][] mind = new int[n][];
		//checking if return is possible
		for(int i = 0; i < n; i++) {
			ArrayList<Flight> a = depart[i];
			if(a.isEmpty()) {
				System.out.println(-1);
				return;
			}
			Collections.sort(a);
			min[i] = new int[a.size()];
			mind[i] = new int[a.size()];
			min[i][a.size()-1] = a.get(a.size()-1).cost;
			mind[i][a.size()-1] = a.size()-1;
			for(int j = a.size()-2; j >= 0; j--) {
				if(a.get(j).cost < min[i][j+1]) {
					min[i][j] = a.get(j).cost;
					mind[i][j] = j;
				} else {
					min[i][j] = min[i][j+1];
					mind[i][j] = mind[i][j+1];
				}
			}
		}
		int[] costs = new int[n];
		int cnt = 0;
		int time = 0;
		long sum = 0;
		Arrays.fill(costs, -1);
		while(cnt != n && !arrive.isEmpty()) {
			Flight fl = arrive.poll();
			if(costs[fl.city] == -1) {
				cnt++;
				sum += costs[fl.city] = fl.cost;
				time = fl.t;
			} else {
				sum -= costs[fl.city];
				costs[fl.city] = Math.min(costs[fl.city], fl.cost);
				sum += costs[fl.city];
			}
		}
		if(cnt != n) {
			System.out.println(-1);
			return;
		}
		long best = sum;
		int[] departind = new int[n];
		for(int i = 0; i < n; i++) {
			int index = binsearch(depart[i],time+k);
			if(index == -1) {
				//System.out.println(i + " does not have valid return");
				//System.out.println(depart[i] + " " + (time+k));
				System.out.println(-1);
				return;
			}
			best += min[i][index];
			departind[i] = mind[i][index];
		}
		while(!arrive.isEmpty()) {
			Flight fl = arrive.poll();
			int curcost = fl.cost;
			int depindex = binsearch(depart[fl.city],fl);
			if(depindex == -1 || depindex == depart[fl.city].size()) continue;
			curcost += min[fl.city][depindex];
			if(curcost < costs[fl.city] + depart[fl.city].get(departind[fl.city]).cost) {
				departind[fl.city] = depindex;
				sum -= costs[fl.city];
				sum += fl.cost;
				costs[fl.city] = fl.cost;
				time = fl.t;
				long curbest = sum;
				for(int i = 0; i < n; i++) {
					int index = binsearch(depart[i],time+k);
					if(index == -1 || index == depart[i].size()) {
						System.out.println(best);
						return;
					}
					while(index != depart[i].size() && depart[i].get(index).t < time+k) index++;
					if(index == -1 || index == depart[i].size()) {
						System.out.println(best);
						return;
					}
					//System.out.println(i + " best dep: " + index);
					curbest += min[i][index];
					departind[i] = mind[i][index];
				}
				//System.out.println();
				if(curbest < best) best = curbest;
			}
		}
		System.out.println(best);
	}
	//approach: store flights back home and iterate over arrival flights in order.
	//if you come across a flight that has the latest arrival < k then stop and print
	//the best so far (theres no more compatible flights). otherwise, bin search for
	//the earliest departure time and find min cost. 
	public int binsearch(ArrayList<Flight> a, Flight i) {
		int l = 0, h = a.size();
		while(l != h) {
			int m = (l+h)/2;
			if(i.compareTo(a.get(m)) > 0) l = m+1;
			else if(i.compareTo(a.get(m)) < 0) h = m;
			else return m;
		}
		return l;
	}public int binsearch(ArrayList<Flight> a, int i) {
		int l = 0, h = a.size();
		while(l != h) {
			int m = (l+h)/2;
			if(i >(a.get(m)).t) l = m+1;
			else if(i < (a.get(m)).t) h = m;
			else return m;
		}
		if(l == a.size()) return -1;
		return l;
	}
	class Flight implements Comparable<Flight> {
		int t, city, cost;
		boolean to;
		public Flight(String s) {
			StringTokenizer st = new StringTokenizer(s);
			t = Integer.parseInt(st.nextToken());
			String next = st.nextToken();
			if(next.equals("0")) {
				to = false;
				city = Integer.parseInt(st.nextToken())-1;
			} else {
				to = true;
				city = Integer.parseInt(next)-1;
				st.nextToken();
			}
			cost = Integer.parseInt(st.nextToken());
		}
		public int compareTo(Flight f) {
			return t - f.t;
		}
		public String toString() {
			return t + " " + city + " " + cost;
		}
	}
}