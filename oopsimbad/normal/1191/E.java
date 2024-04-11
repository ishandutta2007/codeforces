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

		int n = f.nextInt(), k = f.nextInt();

		char[] orig = f.next().toCharArray();

		int[] arr = new int[n];

		for(int i = 0; i < n; i++) arr[i] = orig[i]-'0';

		if(test(arr, 0, k) || test(arr, 1, k)) {

			out.println("tokitsukaze");

			out.flush();

			return;

		}

		boolean lose = true;

		{

			int[] c = new int[n];

			for(int i = 0; i < k; i++) c[i] = 0;

			for(int i = k; i < n; i++) c[i] = arr[i];

			lose &= test(c,0,k) || test(c,1,k);

		}		{

			int[] c = new int[n];

			for(int i = 0; i < k; i++) c[i] = 1;

			for(int i = k; i < n; i++) c[i] = arr[i];

			lose &= test(c,0,k) || test(c,1,k);

		}		{

			int[] c = new int[n];

			for(int i = n-k; i < n; i++) c[i] = 0;

			for(int i = 0; i < n-k; i++) c[i] = arr[i];

			lose &= test(c,0,k) || test(c,1,k);

		}		{

			int[] c = new int[n];

			for(int i = n-k; i < n; i++) c[i] = 1;

			for(int i = 0; i < n-k; i++) c[i] = arr[i];

			lose &= test(c,0,k) || test(c,1,k);

		}

		{

			int[] c = new int[n];

			int first = -1;

			for(int i = 0; i < n; i++) {

				c[i] = arr[i];

				if(first == -1 && c[i] == 0) first = i;

				else if(i - first <= k) c[i] = 1;

			}

			if(first != -1 && first + k < n)lose &= test(c,0,k) || test(c,1,k);

		}

		{

			int[] c = new int[n];

			int first = -1;

			for(int i = 0; i < n; i++) {

				c[i] = arr[i];

				if(first == -1 && c[i] == 1) first = i;

				else if(i - first <= k) c[i] = 0;

			}

			if(first != -1 && first + k < n)lose &= test(c,0,k) || test(c,1,k);

		}

		for(int i = 0; i < n; i++) arr[i] = orig[n-i-1]-'0';

		{

			int[] c = new int[n];

			int first = -1;

			for(int i = 0; i < n; i++) {

				c[i] = arr[i];

				if(first == -1 && c[i] == 0) first = i;

				else if(i - first <= k) c[i] = 1;

			}

			if(first != -1 && first + k < n)lose &= test(c,0,k) || test(c,1,k);

		}

		{

			int[] c = new int[n];

			int first = -1;

			for(int i = 0; i < n; i++) {

				c[i] = arr[i];

				if(first == -1 && c[i] == 1) first = i;

				else if(first != -1 && i - first <= k) c[i] = 0;

			}

			if(first != -1 && first + k < n) lose &= test(c,0,k) || test(c,1,k);

		}

		if(lose) out.println("quailty");

		else out.println("once again");

///
		out.flush(); 
	}
	public boolean test(int[] arr, int val, int k) {
		int first = -1;
		int last = -1;
		for(int i = 0; i < arr.length; i++) {
			if(arr[i] != val) continue;
			if(first == -1) first = i;
			last = i;
		}
		if(last-first+1 <= k) return true;
		return false;
		
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