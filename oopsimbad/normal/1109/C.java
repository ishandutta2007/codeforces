import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	TreeSet<Long> times;
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt();
		Event[] evnts = new Event[n];
		times = new TreeSet<Long>();
		for(int i = 0; i < n; i++) {
			int t = f.nextInt();
			if(t == 1)
				evnts[i] = new Event(t, f.nextInt(), f.nextInt());
			else if(t == 2)
				evnts[i] = new Event(t, f.nextInt());
			else
				evnts[i] = new Event(t, f.nextInt(), f.nextInt(), f.nextInt());
		}
		HashMap<Long,Integer> t_comp = new HashMap<>();
		long[] tarr = new long[times.size()+1];
		{
			int cnt = 0;
			tarr[cnt++] = -1;
			for(long x : times)
				t_comp.put(tarr[cnt] = x, cnt++);
		}
		TreeMap<Integer,Integer> changes = new TreeMap<Integer,Integer>();
		changes.put(0, 0);
		seg3 = new SegTree(tarr.length+1);
		for(Event e : evnts) {
			if(e.type == 1) {
				int t = t_comp.get((long) e.t);
				Map.Entry<Integer, Integer> pc = changes.lowerEntry(t), nc = changes.higherEntry(t);
				if(nc != null) {
					int pt = pc.getKey();
					long pv = pc.getValue();
					int nt = nc.getKey();
					seg3.addRange(nt, (tarr[nt] - tarr[t]) * (e.s - pv) - (tarr[t] - tarr[pt]) * pv);
					seg3.addRange(t, (tarr[t] - tarr[pt]) * pv);
				} else {
					int pt = pc.getKey();
					long pv = pc.getValue();
					seg3.addRange(t, (tarr[t] - tarr[pt]) * pv);
				}
				changes.put(t, e.s);
			} else if(e.type == 2) {
				int t = t_comp.get((long) e.t);
				int ov = changes.get(t);
				Map.Entry<Integer, Integer> pc = changes.lowerEntry(t), nc = changes.higherEntry(t);				
				if(nc != null) {
					int pt = pc.getKey();
					long pv = pc.getValue();
					int nt = nc.getKey();
					seg3.addRange(nt, (tarr[nt] - tarr[t]) * (pv - ov) + (tarr[t] - tarr[pt]) * pv);
					seg3.addRange(t, -(tarr[t] - tarr[pt]) * pv);
				} else {
					int pt = pc.getKey();
					long pv = pc.getValue();
					seg3.addRange(t, -(tarr[t] - tarr[pt]) * pv);
				}
				changes.remove(t);
			} else {
				int l = e.l, r = e.r;
				long v = e.v;
				if(v <= 0) {
					out.println(l);
					continue;
				}
				int rdt = Arrays.binarySearch(tarr, l);
				if(rdt < 0) rdt = ~rdt;
				Map.Entry<Integer,Integer> rd = changes.ceilingEntry(rdt);
				if(rd == null) {
					out.println(-1);
					continue;
				}
				rdt = rd.getKey();
				v = seg3.getMin(rdt, rdt+1) - v;
				int rut = Arrays.binarySearch(tarr, r);
				if(rut < 0) rut = ~rut;
				Map.Entry<Integer,Integer> ru = changes.floorEntry(rut);
				rut = ru.getKey();
				int ruv = ru.getValue();
				int bsl = rdt, bsr = rut+1;
				while(bsl < bsr) {
					int m = (bsl+bsr)/2;
					if(seg3.getMin(rdt, m+1) <= v) bsr = m;
					else bsl = m+1;
				}
				if(bsl == rut+1) {
					if(ruv >= 0) out.println(-1);
					else {
						int time = changes.floorKey(bsl-1);
						long sv = seg3.getMin(time, time+1);
						long temp = -changes.get(time);
						double ans = tarr[time] + (sv - v)/((double) temp);
						long comp = tarr[time] * temp + sv - v;
						if(comp > r*temp || comp < l*temp) out.println(-1);
						else out.println(ans);
					}
				} else {
					int time = changes.floorKey(bsl-1);
					long sv = seg3.getMin(time, time+1);
					long temp = -changes.get(time);
					double ans = tarr[time] + (sv - v)/((double) temp);
					long comp = tarr[time] * temp + sv - v;
					if(comp > r*temp || comp < l*temp) out.println(-1);
					else out.println(ans);
				}
			}
		}
		out.flush();
	}
	SegTree seg3;
	class SegTree {
		long[] mins, lz;
		int n;
		public SegTree(int n) {
			mins = new long[4*n];
			lz = new long[4*n];
			this.n = n;
		}
		public long getMin(int l, int r) {
			long ans =  min(l, r, 0, n, 0); 
			return ans;
		}
		public void addRange(int l, long v) {
			update(l,n,v,0,n,0);
		}
		public long min(int l, int r, int li, int ri, int i) {
			if(l >= ri || r <= li) return Long.MAX_VALUE;
			if(l <= li && r >= ri) return mins[i] + lz[i];
			if(li != ri-1) {
				lz[2*i+1] += lz[i];
				lz[2*i+2] += lz[i];
			}
			mins[i] += lz[i];
			lz[i] = 0;
			int mi = (li+ri)/2;
			return Math.min(min(l,r,li, mi, 2*i+1), min(l,r,mi,ri,2*i+2));
		}
		public void update(int l, int r, long v, int li, int ri, int i) {
			if(l >= ri || r <= li) return;
			if(l <= li && r >= ri) {
				lz[i] += v;
				return;
			}
			if(li != ri-1) {
				lz[2*i+1] += lz[i];
				lz[2*i+2] += lz[i];
			}
			lz[i] = 0;
			int mi = (li+ri)/2;
			update(l, r, v, li, mi, 2*i+1);
			update(l, r, v, mi, ri, 2*i+2);
			mins[i] = Math.min(mins[2*i+1] + lz[2*i+1], mins[2*i+2] + lz[2*i+2]);
		}
	}
	class Event {
		int type;
		int l, r, v, s, t;
		public Event(int...s) {
			type = s[0];
			if(type == 1) {
				t = s[1];
				this.s = s[2];
				times.add((long) t);
			} else if(type == 2) {
				t = s[1];
				times.add((long) t);
			} else {
				l = s[1];
				r = s[2];
				v = s[3];
			}
		}
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
/*
14
1 7 -460747048
1 12 -693247574
2 7
1 7 -679575641
2 7
3 18 25 5
1 32 -177679178
1 10 -552707677
2 10
1 24 -106259
1 7 -102289583
2 12
3 18 27 1
3 22 43 22
*/