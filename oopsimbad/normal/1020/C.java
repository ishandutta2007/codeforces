import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class codeforces {
	public static void main(String[] args) throws Exception {
		new codeforces().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
        int n = f.nextInt(), m = f.nextInt();
        ArrayList<Long>[] votes = new ArrayList[m];
        ArrayList<Long>[] psums = new ArrayList[m];
        for(int i = 0; i < m; i++) {
            votes[i] = new ArrayList<Long>();
            psums[i] = new ArrayList<Long>();
        }
        for(int i = 0; i < n; i++)
            votes[f.nextInt()-1].add(f.nextLong());
            int start = votes[0].size();
        votes[0] = new ArrayList<Long>();
        for(int i = 0; i < m; i++) 
            Collections.sort(votes[i]);
        long ans = Long.MAX_VALUE;
        for(int i = 0; i < n; i++) {
            ArrayList<Long> al = new ArrayList<Long>();
            long cur = 0;
            int cnt = start;
            int max = 0;
            for(ArrayList<Long> vote : votes) {
                max = Math.max(max, Math.min(i,vote.size()));
                for(int j = 0; j < vote.size(); j++) 
                    if(j < vote.size()-i) {
                        cur += vote.get(j);
                        cnt++;
                    }
                    else al.add(vote.get(j));
            }
            Collections.sort(al);
            int j = 0;
            while(cnt <= max) {
                cnt++; 
                cur += al.get(j++);
            }
            ans = Math.min(ans,cur);
        }
        out.println(ans);
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