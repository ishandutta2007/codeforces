import java.io.*;
import java.util.*;

public class Winner implements Runnable {
    private void solve() throws IOException {
        int n = nextInt();
        String[] who = new String[n];
        int[] delta = new int[n];
        Map<String, Integer> sum = new HashMap<String, Integer>();
        for (int i = 0; i < n; ++i) {
            who[i] = nextToken();
            delta[i] = nextInt();
            if (!sum.containsKey(who[i]))
                sum.put(who[i], delta[i]);
            else
                sum.put(who[i], sum.get(who[i]) + delta[i]);
        }
        int max = 0;
        for (Integer x : sum.values())
            max = Math.max(max, x);
        Set<String> possible = new HashSet<String>();
        for (Map.Entry<String, Integer> entry : sum.entrySet())
            if (entry.getValue() >= max)
                possible.add(entry.getKey());
        sum.clear();
        String res = null;
        for (int i = 0; i < n; ++i) {
            if (!sum.containsKey(who[i]))
                sum.put(who[i], delta[i]);
            else
                sum.put(who[i], sum.get(who[i]) + delta[i]);
            if (sum.get(who[i]) >= max && possible.contains(who[i])) {
                res = who[i];
                break;
            }
        }
        writer.println(res);
    }


    public static void main(String[] args) {
        new Winner().run();
    }

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;

    public void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
            writer = new PrintWriter(System.out);
            solve();
            reader.close();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
}