import java.io.*;
import java.util.*;

public class GraphRatios {
  public static ArrayList<Integer>[] graph;
  public static int[] deg, cur;
  public static boolean[] vis;
  
  public static void main (String[] args) {
    InputReader in = new InputReader(System.in);
    PrintWriter out = new PrintWriter(System.out, true);
    
    int N = in.nextInt(), M = in.nextInt(), K = in.nextInt();
    vis = new boolean[N];
    for (int i = 0; i < K; i++) vis[in.nextInt()-1] = true;
    deg = new int[N]; 
    cur = new int[N];
    graph = new ArrayList[N];
    for (int i = 0; i < N; i++) graph[i] = new ArrayList<>();
    for (int i = 0; i < M; i++) {
      int a = in.nextInt()-1, b = in.nextInt()-1;
      graph[a].add(b);
      graph[b].add(a);
      deg[a]++;
      deg[b]++;
      if (vis[a]) cur[b]++;
      if (vis[b]) cur[a]++;
    }
    PriorityQueue<State> pq = new PriorityQueue<State>();
    for (int i = 0; i < N; i++) if (!vis[i]) {
      pq.add (new State(i, cur[i]));
    }
    
    long num = 1, den = 1;
    int[] lst = new int[N];
    int idx = 0;
    int best = 0;
    while (pq.size() > 0) {
      State s = pq.poll();
      if (cur[s.node] != s.val || vis[s.node]) continue;
      lst[idx++] = s.node;
      long tn = s.val, td = deg[s.node];
      if (num * td > den * tn) {num = tn; den = td; best = idx-1;}
      vis[s.node] = true;
      for (int neighbor : graph[s.node]) if (!vis[neighbor]) {
        pq.add(new State(neighbor, ++cur[neighbor]));
      }
    }
    
    int[] res = new int[idx-best];
    for (int i = best; i < idx; i++) res[i-best] = lst[i]+1;
    // randomize order of output, just because I can.
    for (int i = 0; i < res.length; i++) {
      int j = (int)(Math.random() * (i+1));
      if (j == i) continue;
      int t = res[i]; res[i] = res[j]; res[j] = t;
    }
    out.println(res.length);
    for (int i = 0; i < res.length; i++) {
      if (i != 0) out.print(" ");
      out.print(res[i]);
    }
    out.println();
    out.close();
    System.exit(0);
  }
  
  public static long gcd(long a, long b) {
    return b == 0 ? a : gcd(b, a % b);
  }
  
  static class State implements Comparable<State> {
    public int node;
    public long val;
    public State(int node, int val) {
      this.node = node;
      this.val = val;
    }
    
    public int compareTo(State other) {
      return (int)(Math.signum(deg[node] * other.val - val * deg[other.node]));
    }
  }
  
  static class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
      reader = new BufferedReader(new InputStreamReader(stream), 32768);
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
  }
}