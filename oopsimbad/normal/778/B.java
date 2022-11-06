import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class B {
	public static void main(String[] args) throws Exception {
		new B().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
        int n = f.nextInt(), m = f.nextInt();
        HashMap<String,int[]> hm = new HashMap<>();
        {
            int[] tmp = new int[m];
            Arrays.fill(tmp,2);
            hm.put("?", tmp);
        }
        for(int asdf = 0; asdf < n; asdf++) {
            String[] arr = f.nextLine().split(" ");
            String name = arr[0];
            if(arr.length == 3 ) hm.put(name, parse(arr[2]));
            else {
                int[] a1 = hm.get(arr[2]);
                int[] a2 = hm.get(arr[4]);
                int[] na = new int[m];
                if(arr[3].equals("AND")) {
                    for(int i = 0; i < m; i++) {
                        if(a1[i] == 0 || a2[i] == 0) na[i] = 0;
                        else if(a1[i] == 1 || a2[i] == 1) na[i] = a1[i] + a2[i] - 1;
                        else if(a1[i] != a2[i]) na[i] = 0;
                        else na[i] = a1[i];
                    }
                }
                if(arr[3].equals("OR")) {
                    for(int i = 0; i < m; i++) {
                        if(a1[i] == 1 || a2[i] == 1) na[i] = 1;
                        else if(a1[i] == 0 || a2[i] == 0) na[i] = a1[i] + a2[i];
                        else if(a1[i] != a2[i]) na[i] = 1;
                        else na[i] = a1[i];
                    }
                }
                if(arr[3].equals("XOR")) {
                    for(int i = 0; i < m; i++) {
                        na[i] = a1[i] ^ a2[i];
                    }
                }
                hm.put(name, na);
            }
        }
        int[] total = new int[m];
        hm.remove("?");
        for(String s : hm.keySet()) {
            int[] t = hm.get(s);
            //out.println(s + " " + Arrays.toString(t));
            for(int i = 0; i < m; i++)
                if(t[i] == 2) total[i]++;
                else if(t[i] == 3) total[i]--;
        }
        for(int i = 0; i < m; i++)
            out.print(total[i] >= 0 ? 0 : 1);
        out.println();
        for(int i = 0; i < m; i++)
            out.print(total[i] <= 0 ? 0 : 1);
        out.flush();
	}
    int[] parse(String s) {
        int[] arr = new int[s.length()];
        for(int i = 0; i < s.length(); i++)
            arr[i] = s.charAt(i)-'0';
        return arr;
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