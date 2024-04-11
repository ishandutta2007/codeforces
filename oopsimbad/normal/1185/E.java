import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class E {
	public static void main(String[] args) throws Exception {
		new E().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);
        int times = f.nextInt();
        while(times-->0) {
            int r = f.nextInt(), c = f.nextInt();
            char[][] mat = new char[r][];
            int[][] topLeft = new int[26][2];
            int[][] botRght = new int[26][2];
            for(int i = 0; i < 26; i++)
                for(int j = 0;j < 2; j++) {
                    topLeft[i][j] = 2147483647;
                    botRght[i][j] = -1;
                }
            for(int i = 0; i < r; i++) {
                mat[i] = f.next().toCharArray(); 
                for(int j = 0; j < c; j++) {
                    if(Character.isAlphabetic(mat[i][j])) {
                        int v = mat[i][j]-'a';
                        topLeft[v][0] = Math.min(topLeft[v][0],i);
                        topLeft[v][1] = Math.min(topLeft[v][1],j);
                        botRght[v][0] = Math.max(botRght[v][0],i);
                        botRght[v][1] = Math.max(botRght[v][1],j);
                    }
                }
            }
            int cur = 25;
            while(cur >= 0 && botRght[cur][0] == -1) cur--;
            Stack<int[]> s = new Stack<>();
            boolean poss = true;
            for(int i = cur; i >= 0; i--) {
                int r1 = topLeft[i][0], r2 = botRght[i][0], c1 = topLeft[i][1], c2 = botRght[i][1]; 
                if(r1 == 2147483647) {
                    topLeft[i][0] = topLeft[i+1][0];
                    topLeft[i][1] = topLeft[i+1][1];
                    botRght[i][0] = botRght[i+1][0];
                    botRght[i][1] = botRght[i+1][1];
                    continue;
                }
                if(r1 != r2 && c1 != c2) {
                    poss = false;
                    break;
                }
                
                for(int a = r1; a <= r2 && poss; a++)
                    for(int b = c1; b <= c2 && poss; b++) {
                        poss &= mat[a][b] == 'a'+i || mat[a][b] == '?';
                        mat[a][b] = '?';
                    }
            }
            if(poss) {
                out.println("YES");
                out.println(cur+1);
                for(int i = 0; i <= cur; i++) {
                    out.printf("%d %d %d %d%n", topLeft[i][0]+1, topLeft[i][1]+1, botRght[i][0]+1, botRght[i][1]+1);
                }
            } else out.println("NO");
        }
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