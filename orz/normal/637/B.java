import java.io.*;
import java.util.*;

/**
 * Created by asus on 13.03.2016.
 */
public class B_Chat {

    public static void main(String[] args) {
        new B_Chat().run();
    }

    private void run() {
        IO files = new IO();
        int n = files.nextInt();

        TreeSet<User> users = new TreeSet<>();
        HashSet<String> names = new HashSet<>();
        int[] priority = new int[n];
        HashMap<String, Integer> map = new HashMap<>();
        int t = 0;
        int prior = Integer.MAX_VALUE;

        for (int i = 0; i < n; i++) {
            String name = files.next();
            if (!names.contains(name)) {
                names.add(name);
                map.put(name, t);
                users.add(new User(name, prior));
                priority[t] = prior;
                t++;
                prior--;
            } else {
                User next = new User(name, priority[map.get(name)]);
                users.remove(next);
                next.value = prior;
                priority[map.get(name)] = prior;
                prior--;
                users.add(next);
            }
        }

        for (User user : users) {
            files.println(user.name);
        }

        files.close();
    }

    private class User implements Comparable<User> {
        String name;
        int value;

        public User(String name, int value) {
            this.name = name;
            this.value = value;
        }

        @Override
        public int compareTo(User o) {
            return Integer.compare(value, o.value);
        }

        @Override
        public boolean equals(Object o) {
            User u = (User) o;
            return (value == u.value && Objects.equals(name, u.name));
        }
    }

    private class IO {
        BufferedReader in;
        PrintWriter out;
        StringTokenizer st;

        public IO(String name) {
            try {
                in = new BufferedReader(new FileReader(name + ".in"));
                out = new PrintWriter(name + ".out");
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public IO() {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
        }

        String nextLine() {
            String s = null;
            while (s == null) {
                try {
                    s = in.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return s;
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(in.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        void print(Object s) {
            out.print(s);
        }

        void println(Object s) {
            out.println(s);
        }

        void close() {
            out.close();
        }
    }

}