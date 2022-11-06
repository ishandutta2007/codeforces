import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	int[] arr;
	int cur;
	int[] lazy;
	int[] vals;
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int ncnt = f.nextInt();
		int[] st = new int[ncnt], end = new int[ncnt];
		TreeNode[] tn = new TreeNode[ncnt];
		arr = new int[ncnt];
		for(int i = 0; i < ncnt; i++) 
			tn[i] = new TreeNode(i);
		for(int i = 1; i < ncnt; i++)
			tn[f.nextInt()-1].children.add(tn[i]);
		for(int i = 0; i < ncnt; i++)
			tn[i].val = f.nextInt();
		tn[0].traverse(st, end);
		lazy = new int[4*ncnt];
		vals = new int[4*ncnt];
		//System.out.println(Arrays.toString(st));
		//System.out.println(Arrays.toString(end));
		build(1,0,ncnt);
		int qcnt = f.nextInt();
		while(qcnt-->0) {
			String s = f.next();
			int i =f.nextInt()-1;
			if(s.equals("get")) {
				out.println(query(1, 0, ncnt, st[i], end[i]));
			} else {
				update(1,0,ncnt,st[i], end[i]);
			}
			//print(1, 0, ncnt);
			//System.out.println();
		}
		out.flush();
	}
	public void print(int i, int l, int r) {
		System.out.println(i + " " + l + "-" + r + " val:" + vals[i] + " lazy:" + lazy[i]);
		if(l != r-1) {
			int m = (l+r)/2;
			print(2*i, l, m);
			print(2*i+1, m, r);
		}
	}
	public int query(int i, int l, int r, int tl, int tr) {
		if(r <= tl || l >= tr) return 0;
		if(lazy[i] != 0) {
			prop(i, l, r);
		}
		if(tr >= r && tl <= l) return vals[i];
		if(l == r-1) return 0;
		int m = (l+r)/2;
		return query(2*i, l, m, tl, tr) + query(2*i+1, m, r, tl, tr);
	}
	public void update(int i, int l, int r, int tl, int tr) {
		if(lazy[i] == 1) prop(i, l, r);
		if(r <= tl || l >= tr) {
			return;
		}
		if(tr >= r && tl <= l) {
			prop(i, l, r);
		}
		else if(l != r-1) {
			int m = (l+r)/2;
			update(2*i, l, m, tl, tr);
			update(2*i+1, m, r, tl, tr);
			vals[i] = vals[2*i] + vals[2*i+1];
		}
	}
	public void prop(int i, int l, int r) {
		lazy[i] = 0;
		vals[i] = r-l-vals[i];
		if(l != r-1) {
			lazy[2*i] ^= 1;
			lazy[2*i+1] ^= 1;
		}
	}
	public void build(int i, int l, int r) {
		if(l == r-1) vals[i] = arr[l];
		else {
			int m = (l+r)/2;
			build(2*i, l, m);
			build(2*i+1, m, r);
			vals[i] = vals[2*i] + vals[2*i+1];
		}
	}
	class TreeNode {
		LinkedList<TreeNode> children;
		int id;
		int val;
		public TreeNode(int n) {
			id = n;
			children = new LinkedList<TreeNode>();
		}
		public void traverse(int[] st, int[] end) {
			st[id] = cur;
			arr[cur] = val;
			cur++;
			for(TreeNode n : children)
				n.traverse(st, end);
			end[id] = cur;
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