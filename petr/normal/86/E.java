import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class SeqGen implements Runnable {
    private void solve() throws IOException {
        long[] answer = new long[51];
        answer[2] = 3L;
        answer[3] = 5L;
        answer[4] = 25L;
        answer[5] = 59L;
        answer[6] = 97L;
        answer[7] = 239L;
        answer[8] = 95L;
        answer[9] = 119L;
        answer[10] = 507L;
        answer[11] = 3487L;
        answer[12] = 7333L;
        answer[13] = 4313L;
        answer[14] = 9541L;
        answer[15] = 32057L;
        answer[16] = 53035L;
        answer[17] = 189143L;
        answer[18] = 486961L;
        answer[19] = 602161L;
        answer[20] = 692181L;
        answer[21] = 3749685L;
        answer[22] = 5666119L;
        answer[23] = 2612725L;
        answer[24] = 28939211L;
        answer[25] = 48906931L;
        answer[26] = 130097631L;
        answer[27] = 223561211L;
        answer[28] = 339419171L;
        answer[29] = 478475725L;
        answer[30] = 1513517851L;
        answer[31] = 4151082213L;
        answer[32] = 3067098099L;
        answer[33] = 815774593L;
        answer[34] = 30919633783L;
        answer[35] = 6639234397L;
        answer[36] = 63406103045L;
        answer[37] = 196974070485L;
        answer[38] = 160715692415L;
        answer[39] = 649067163679L;
        answer[40] = 1968703023731L;
        answer[41] = 4199885479225L;
        answer[42] = 5260526710483L;
        answer[43] = 11350565584815L;
        answer[44] = 18000475705097L;
        answer[45] = 30474977225109L;
        answer[46] = 13504636890057L;
        answer[47] = 33940824593261L;
        answer[48] = 20636564487877L;
        answer[49] = 18707714161455L;
        answer[50] = 20540225290239L;
        int k = nextInt();
        for (int i = 0; i < k; ++i) {
            if (i > 0) writer.print(" ");
            writer.print((answer[k] >> (k - 1 - i)) & 1);
        }
        writer.println();
        for (int i = 0; i < k; ++i) {
            if (i > 0) writer.print(" ");
            writer.print(1);
        }
        writer.close();
    }

    public static void main(String[] args) {
        new SeqGen().run();
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