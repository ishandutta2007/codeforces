import java.io.*;
import java.util.*;
import java.io.DataInputStream;
import java.io.InputStream;

public class Main {
    public static void main(String[] args) throws IOException {
        Locale.setDefault(Locale.US);
        Scanner sc = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int m = sc.nextInt();
        Deque<Integer> b = new ArrayDeque<>();
        Deque<Integer> c = new ArrayDeque<>();
        for (int i = 0; i < n; i++) {
            b.add(sc.nextInt());
        }
        for (int i = 0; i < m; i++) {
            c.add(sc.nextInt());
        }
        int ans = 0;
        while (!c.isEmpty() && !b.isEmpty()) {
            int a = b.pollFirst();
            if (c.peekFirst() >= a) {
                c.pollFirst();
                ans++;
            }
        }
        pw.println(ans);
        pw.close();
    }
}