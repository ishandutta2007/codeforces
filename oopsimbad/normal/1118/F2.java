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
		int n = f.nextInt(), k= f.nextInt();
		Node[] arr = new Node[n];
		for(int i = 0; i < n; i++)
			arr[i] = new Node(i,f.nextInt());
		for(int i = 0; i < n-1; i++) {
			int a= f.nextInt()-1, b = f.nextInt()-1;
			arr[a].child.add(arr[b]);
			arr[b].child.add(arr[a]);
		}
		Node[] colors = new Node[k+1];
		arr[0].pre(null);
		for(Node no : arr) {
			if(no.c == 0) continue;
			Node a = colors[no.c];
			if(a == null) colors[no.c] = no;
			else colors[no.c] = LCA(a, no);
		}
		for(int i = 1; i <= k; i++)
			colors[i].endColor = i;
		hasAns = true;
		LinkedList<Node> ll = new LinkedList<>();
		for(Node no : arr)
			if(no.child.size() == 0) ll.add(no);
		while(hasAns && !ll.isEmpty()) {
			Node no = ll.removeFirst();
			no.dp();
			no = no.anc[0];
			if(no == null) continue;
			if(++no.childCnt == no.child.size()) ll.addLast(no);
		}
		if(hasAns)
			out.println(arr[0]._hasntEnd);
		else
			out.println(0);
		out.flush();
	}
	boolean hasAns;
	public Node LCA(Node a, Node b) {
		if(a.d < b.d) {
			Node temp = a;
			a = b;
			b = temp;
		}
		for(int i = 19; i >= 0; i--)
			if(a.anc[i] != null && a.anc[i].d >= b.d) 
				a = a.anc[i];
		if(a == b) return a;
		for(int i = 19; i >= 0; i--)
			if(a.anc[i] != null && b.anc[i] != null && a.anc[i] != b.anc[i]) {
				a = a.anc[i];
				b = b.anc[i];
			}
		return a.anc[0];
	} 
	class Node {
		Node[] anc;
		int i, c, d;
		int endColor, retColor, childCnt;
		long _didEnd, _hasntEnd;
		LinkedList<Node> child;
		public Node(int i, int c) {
			this.i = i;
			this.c = c;
			child = new LinkedList<Node>();
		}
		public void pre(Node n) {
			anc = new Node[20];
			d = (n == null ? 0 : n.d + 1);
			anc[0] = n;
			for(int i = 1; i < 20; i++)
				if(anc[i-1] != null)
					anc[i] = anc[i-1].anc[i-1];
				else
					break;
			child.remove(n);
			for(Node c : child)
				c.pre(this);
		}
		public String toString() {
			return ""+i;
		}
		public void dp() {
			if(!hasAns) return;
			if(child.size() == 0) {
				if(endColor != 0) _hasntEnd = 1;
				else _didEnd = 1;
				//System.out.println("Node " + i + " ended:" + _didEnd + " hasnt:" + _hasntEnd + " " + endColor);
				if(endColor != 0) retColor = 0;
				else retColor = c;
			} else {
				long totalprod = 1;
				int propColor = c;
				for(Node c : child) {
					int color = c.retColor;
					if(propColor != 0 && color != 0 && propColor != color) hasAns = false;
					else if(propColor == 0) propColor = color;
					totalprod = totalprod * (c._didEnd + c._hasntEnd) % MOD;
				}
				if(endColor != 0 && propColor != endColor) hasAns = false;
				if(propColor == 0) {
					_didEnd = totalprod;
					for(Node c : child) {
						_hasntEnd = (_hasntEnd + (totalprod * modInv(c._didEnd + c._hasntEnd)) % MOD * c._hasntEnd % MOD) % MOD;
					}
				} else _hasntEnd = totalprod;
				//System.out.println("Node " + i + " ended:" + _didEnd + " hasnt:" + _hasntEnd + " " + endColor + " " + propColor);
				if(propColor == endColor) retColor = 0;
				else retColor = propColor;
			}
			
		}
	}
	long x, y, MOD = 998_244_353;
	public long modInv(long val) {
		gcd(val, MOD);
		return (x % MOD + MOD) % MOD;
	}
	public void gcd(long a, long b) {
		if(a * b == 0) {
			x = 0;
			y = 1;
			return;
		}
		gcd(b%a,a);
		long nx = y - b/a * x;
		long ny = x;
		x = nx;
		y = ny;
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