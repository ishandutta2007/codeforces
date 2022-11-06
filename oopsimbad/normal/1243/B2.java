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
		int asdf = f.nextInt();
		while(asdf-->0) {
			int n = f.nextInt();
			char[] a = f.next().toCharArray();
			char[] b = f.next().toCharArray();
			boolean[] used = new boolean[n];
			int curind = 0;
			boolean works = true;
			ArrayList<Integer> moves = new ArrayList<>();
			for(char c = 'a'; c <= 'z'; c++) {
				int i = 0, j = 0;
				while(true) {
					while(i < n && a[i] != c) i++;
					while(j < n && b[j] != c) j++;
					if(i == n && j == n) break;
					else if(j == n) {
						int p = i++;
						while(true) {
							while(i < n && a[i] != c) i++;
							if(i == n) break;
							else if(p == -1) p = i;
							else {
								moves.add(i);
								moves.add(p);
								a[i] = b[p];
								b[p] = c;
								used[p] = true;
								p = -1;
							}
							i++;
						}
						if(p != -1) works = false;
						break;
					} else if(i == n) {
						int p = j++;
						while(true) {
							while(j < n && b[j] != c) j++;
							if(j == n) break;
							else if(p == -1) p = j;
							else{
								moves.add(p);
								moves.add(j);
								b[j] = a[p];
								a[p] = c;
								used[p] = true;
								p = -1;
							}
							j++;
						}
						if(p != -1) works = false;
						break;
					} else {
						while(used[curind]) curind++;	
						if(i == curind) {
							moves.add(i);
							moves.add(curind);
							a[i] = b[curind];
							b[curind] = c;
							moves.add(curind);
							moves.add(j);
							b[j] = a[curind];
							a[curind] = c;
						} else {
							moves.add(curind);
							moves.add(j);
							b[j] = a[curind];
							a[curind] = c;
							moves.add(i);
							moves.add(curind);
							a[i] = b[curind];
							b[curind] = c;
						}
						used[curind] = true;
						curind++;
						i++; j++;
					}
				}
			}
			if(works) {
				out.println("Yes");
				out.println(moves.size()/2);
				for(int i = 0; i < moves.size(); i+= 2) out.println(moves.get(i)+1 + " " + (moves.get(i+1)+1));
			} else out.println("No");
		}
///
		out.flush(); 
	}
///
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