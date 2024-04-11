import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		
		int times = f.nextInt();
		HashMap<String,Integer> hm = new HashMap<String,Integer>();
		HashMap<String,ArrayList<Long>> hm2 = new HashMap<String,ArrayList<Long>>();
		for(int i = 0; i < times; i++) {
			String n = f.next();
			int a = f.nextInt();
			if(hm.containsKey(n)) {
				hm.put(n,(hm.get(n) + a));
				hm2.get(n).add((long) a << 32 | i);
			}
			else {
				hm.put(n, a);
				hm2.put(n, new ArrayList<Long>());
				hm2.get(n).add((long) a << 32 | i);
			}
		}
		String best = "";
		long l = Long.MIN_VALUE;
		int bi = 0;
		for(String s : hm.keySet()) {
			long cur = hm.get(s);
			int ji = 0;
			ArrayList<Long> al = hm2.get(s);
			long temp = 0;
			for(;ji < al.size(); ji++) {
				temp += al.get(ji) >> 32;
				if(temp >= cur) {
					ji = (int) (al.get(ji) << 32 >> 32);
					break;
				}
			}
			if(cur > l) {
				best = s;
				l = hm.get(s);
				bi = ji;
			} else if(cur == l && ji < bi) {
				best = s;
				l = hm.get(s);
				bi = ji;
			}
		}
		out.println(best);
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

    }
}