import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Set;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.TreeSet;
import java.util.HashSet;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Comparator;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        TaskB.Bundle mergeMembers(TaskB.Bundle b1, TaskB.Bundle b2) {
            if (b1.members.size() > b2.members.size()) {
                for (TaskB.Person p : b2.members) p.where = b1;
                b1.members.addAll(b2.members);
                b2.members.clear();
                return b1;
            } else {
                for (TaskB.Person p : b1.members) p.where = b2;
                b2.members.addAll(b1.members);
                b1.members.clear();
                return b2;
            }
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            TaskB.Person[] people = new TaskB.Person[n];
            TreeSet<TaskB.Person> peopleSet = new TreeSet<>(new Comparator<TaskB.Person>() {

                public int compare(TaskB.Person o1, TaskB.Person o2) {
                    int z = o1.money - o2.money;
                    if (z == 0) z = o1.id - o2.id;
                    return z;
                }
            });
            for (int i = 0; i < n; ++i) {
                people[i] = new TaskB.Person(i);
                people[i].money = in.nextInt();
                peopleSet.add(people[i]);
            }
            TreeSet<TaskB.Bundle> bundleSet = new TreeSet<>(new Comparator<TaskB.Bundle>() {

                public int compare(TaskB.Bundle o1, TaskB.Bundle o2) {
                    int z = o1.money - o2.money;
                    if (z == 0) z = o1.id - o2.id;
                    return z;
                }
            });
            int nq = in.nextInt();
            for (int i = 0; i < nq; ++i) {
                int kind = in.nextInt();
                if (kind == 1) {
                    TaskB.Person p = people[in.nextInt() - 1];
                    if (p.where != null) {
                        if (!p.where.members.remove(p)) throw new RuntimeException();
                        p.where = null;
                    } else {
                        if (!peopleSet.remove(p)) throw new RuntimeException();
                    }
                    p.money = in.nextInt();
                    if (!peopleSet.add(p)) throw new RuntimeException();
                } else if (kind == 2) {
                    int bound = in.nextInt();
                    TaskB.Bundle b = new TaskB.Bundle(i);
                    while (!peopleSet.isEmpty() && peopleSet.first().money < bound) {
                        TaskB.Person p = peopleSet.pollFirst();
                        p.where = b;
                        b.members.add(p);
                    }
                    while (!bundleSet.isEmpty() && bundleSet.first().money < bound) {
                        b = mergeMembers(b, bundleSet.pollFirst());
                    }
                    b.money = bound;
                    if (!bundleSet.add(b)) throw new RuntimeException();
                } else throw new RuntimeException();
            }
            for (TaskB.Person p : people) {
                if (p.where == null) {
                    out.print(p.money);
                } else {
                    out.print(p.where.money);
                }
                out.print(" ");
            }
            out.println();
        }

        static class Person {
            int id;
            int money;
            TaskB.Bundle where;

            public Person(int id) {
                this.id = id;
            }

        }

        static class Bundle {
            int id;
            int money;
            Set<TaskB.Person> members = new HashSet<>();

            public Bundle(int id) {
                this.id = id;
            }

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