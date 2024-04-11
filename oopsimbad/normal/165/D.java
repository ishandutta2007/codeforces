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
		int maxDegree = 0;
		Node root = null;
		Node[] nodes = new Node[n];
		Edge[] edges = new Edge[n-1];
		for(int i = 0; i < n; i++)
			nodes[i] = new Node(i);
		for(int i = 0; i < n-1; i++) {
			int n1 = f.nextInt()-1, n2 = f.nextInt()-1;
			nodes[n1].children.add(nodes[n2]);
			nodes[n2].children.add(nodes[n1]);
			edges[i] = new Edge();
			edges[i].n1 = nodes[n1];
			edges[i].n2 = nodes[n2];
			edges[i].black = true;
		}
		for(Node node : nodes) {
			if(node.children.size() > maxDegree) {
				maxDegree = node.children.size();
				root = node;
			}
		}
		BITsize = 1;
		BITsizes = new int[n];
		BITstarts = new int[n];
		BIT = new int[n];
		root.visited = true;
		int chaincnt = 0;
		for(Node c : root.children){
			BITstarts[chaincnt] = BITsize;
			recur(c,1,chaincnt++);
		}
		int m = f.nextInt();
		while(m-->0) {
			int id = f.nextInt();
			if(id == 1) {
				int en = f.nextInt()-1;
				if(!edges[en].black) {
					edges[en].black = true;
					if(edges[en].n1.dist > edges[en].n2.dist) add(edges[en].n1.BITloc,-1);
					else add(edges[en].n2.BITloc,-1);
				}
			} else if(id == 2) {
				int en = f.nextInt()-1;
				if(edges[en].black) {
					edges[en].black = false;
					if(edges[en].n1.dist > edges[en].n2.dist) add(edges[en].n1.BITloc,1);
					else add(edges[en].n2.BITloc,1);
				}
				
			} else {
				Node n1 = nodes[f.nextInt()-1], n2 = nodes[f.nextInt()-1];
				int q1 = n1 == root ? 0
						: query(n1.BITloc)-
							query(BITstarts[n1.pathnum]-1),
					q2 = n2 == root ? 0 
						: query(n2.BITloc)-
						 query(BITstarts[n2.pathnum]-1);
				
				if(n1.pathnum == n2.pathnum) q2 *= -1;
				int total = Math.abs(q1+q2);
				if(total > 0) out.println(-1);
				else out.println(Math.abs(n1.dist + (n1.pathnum == n2.pathnum ? -1 : 1) * n2.dist));
			}
		}
 		out.flush();
	}
	int BITsize;
	int[] BITsizes;
	int[] BITstarts;
	int[] BIT;
	class Edge {
		Node n1, n2;
		boolean black;
	}
	public void recur(Node n, int d, int pn) {
		if(n.visited) return;
		n.visited = true;
		n.pathnum = pn;
		n.dist = d;
		BITsizes[pn]++;
		n.BITloc = BITsize++;
		for(Node c : n.children) recur(c,d+1,pn);
	}
	public void add(int index, int val) {
		while(index < BIT.length) {
			BIT[index] += val;
			index += index & -index;
		}
	}
	public int query(int index) {
		int res = 0;
		while(index > 0) {
			res += BIT[index];
			index -= index & -index;
		}
		return res;
	}
	class Node {
		int id,pathnum,dist,BITloc;
		ArrayList<Node> children;
		boolean visited;
		public Node(int i) {
			children = new ArrayList<Node>();
			id = i;
		}
		public String toString() {
			return id + " " + pathnum;
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