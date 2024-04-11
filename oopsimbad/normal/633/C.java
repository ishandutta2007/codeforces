import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	char[] target;
	int n,m;
	char[][] words;
	Tree tree;
	A[] path;
	A begin;
	int pl;
	boolean stop;
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		stop = false;
		n = f.nextInt();
		target = f.next().toCharArray();
		m = f.nextInt();
		words = new char[m][];
		tree = new Tree();
		for(int i = 0; i < m; i++) {
			words[i] = f.next().toCharArray();
			tree.add(i);
		}
		path = new A[n];
		pl = 0;
		recur(n-1,-1);
		//System.out.println(Arrays.toString(path));
		A a = begin;
		while(true) {
			out.print(words[a.use]);
			out.print(' ');
			if(a.from == -1) break;
			a = path[a.from];
		}
		out.flush();
	}	
	class A {
		int use;
		int from;
		public A(int i, int j) {
			use = i;
			from = j;
		}
		public String toString() {
			return use + " <=" + from;
		}
	}
	public A recur(int index, int from) {
		if(stop) return path[index];
		if(path[index] != null) return path[index];
		int ii = index;
		Tree.Node n = tree.root;
		while(true) {
			if(n.n != -1) {
				if(index == -1) {
					stop = true;
					
					return begin = path[ii] = new A(n.n,from);
				}
				recur(index,ii);
				if(stop)
					return path[ii] = new A(n.n,from);
			}
			if(index < 0) break;
			int a = target[index--] - 'a';
			if(a < 0) a += 32;
			n = n.children[a];
			if(n == null) break;
		}
		return path[ii] = new A(-1,-1);
	}
	
	class Tree {
		Node root;
		public Tree() {
			root = new Node(-1);
		}
		public void add(int i) {
			root.add(words[i], 0, i);
		}
		class Node {
			Node[] children;
			int n;
			public Node(int i) {
				n = i;
				children = new Node[26];
			}
			public void add(char[] arr, int ci, int val) {
				if(ci == arr.length) {
					n = val;
					return;
				}
				int a = arr[ci] - 'a';
				if(a < 0) a += 32;
				if(children[a] == null) children[a] = new Node(-1);
				children[a].add(arr, ci+1, val);
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

    }
}