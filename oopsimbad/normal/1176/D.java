import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class D {
	public static void main(String[] args) throws Exception {
		new D().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt();
		boolean[] sieve = new boolean[2800000];
		int pcnt = 0;
		HashMap<Integer,Integer> hm = new HashMap<>();
		for(int i = 2; i < sieve.length; i++) 
			if(sieve[i]) continue;
			else {
				if(sieve.length / i >= i) for(int j = i*i; j < sieve.length; j += i) sieve[j] = true;
				hm.put(i,++pcnt);
			}
		ArrayList<Integer> al = new ArrayList<Integer>();
		boolean[] used = new boolean[2*n];
		for(int i = 0; i < 2*n; i++)
			al.add(f.nextInt());
		Collections.sort(al);
		ArrayList<Integer> ans = new ArrayList<>();
		HashMap<Integer,Integer> idx = new HashMap<>();
		for(int i = 0; i < 2*n; i++)
			idx.put(al.get(i),i);
		boolean works = true;
		for(int i = 2*n-1; i >= 0; i--) {
			if(used[i]) continue;
			int a = al.get(i);
			int greatest = -1;
			for(int j = 2; j*j <= a; j++) 
				if(a % j == 0) {
					greatest = a/j;
					break;
				}
			boolean addG = false;
			if(greatest == -1) {
				greatest = hm.get(a);
				addG = true;
			}
			if(!idx.containsKey(greatest)) continue;
			int ind;
			used[ind = idx.get(greatest)] = true;
			used[i] = true;
			if(ind == 0 || al.get(ind-1) != greatest) idx.remove(greatest);
			else idx.put(greatest, ind-1);
			if(addG) ans.add(greatest);
			else ans.add(a);
		}
		for(int i : ans) out.print(i + " ");	
        out.flush();
	}
    static class FastScanner {
        public BufferedReader reader;
        public StringTokenizer tokenizer;
        public FastScanner() {
            reader = new BufferedReader(new InputStreamReader(System.in), 32768);
            tokenizer = null;
        }
        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }
        public int nextInt() {
            return Integer.parseInt(next());
        }
        public long nextLong() {
        	return Long.parseLong(next());
        }
        public double nextDouble() {
        	return Double.parseDouble(next());
        }
        public String nextLine() {
        	try {
        		return reader.readLine();
        	} catch(IOException e) {
        		throw new RuntimeException(e);
        	}
        }
    }
}