import java.io.*;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;


    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int t = sc.nextInt();
        for(int q = 0;q < t;q++) {
            char h[] = sc.next().toCharArray();
            ArrayList<Integer> ans = new ArrayList<>();
            ArrayList<Integer> v = new ArrayList<>();
            for(int i = 0;i < h.length;i++) {
                v.add(i);
                if (v.size() < 3) continue;
                int y = v.size() - 1;
                if (h[v.get(y - 2)] == 'o' && h[v.get(y - 1)] == 'n' && h[v.get(y)] == 'e') {
                    ans.add(v.get(y - 1));
                    v.remove(y - 1);
                }else if (h[v.get(y - 2)] == 't' && h[v.get(y - 1)] == 'w' && h[v.get(y)] == 'o') {
                    if (i + 1 >= h.length || h[i + 1] != 'o') {
                        ans.add(v.get(y));
                        v.remove(y);
                    } else {
                        ans.add(v.get(y - 1));
                        v.remove(y - 1);
                    }
                }
            }

            pw.println(ans.size());
            for(int i : ans) pw.print(i + 1 + " ");
            pw.println();
        }

        pw.close();
    }

    static Scanner sc;
    static PrintWriter pw;

    static class Scanner {
        BufferedReader br;
        StringTokenizer st = new StringTokenizer("");

        Scanner(InputStream in) throws FileNotFoundException {
            br = new BufferedReader(new InputStreamReader(in));
        }

        Scanner(String in) throws FileNotFoundException {
            br = new BufferedReader(new FileReader(in));
        }

        String next() throws IOException {
            while (!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
    }

}