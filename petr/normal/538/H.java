import java.util.TreeMap;
import java.util.ArrayList;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.List;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Collections;
import java.util.Comparator;
import java.io.IOException;
import java.util.StringTokenizer;

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
		TaskH solver = new TaskH();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskH {
    static class Teacher {
        int l;
        int r;
        List<Teacher> conflicts = new ArrayList<>(1);
        int kind;
        int res;

        public boolean buildComponent(Component c, int k) {
            if (kind != 0) {
                return kind == k;
            }
            kind = k;
            if (k == 1) {
                c.l1 = Math.max(c.l1, l);
                c.r1 = Math.min(c.r1, r);
            } else {
                c.l2 = Math.max(c.l2, l);
                c.r2 = Math.min(c.r2, r);
            }
            for (Teacher t : conflicts) {
                if (!t.buildComponent(c, 3 - k)) return false;
            }
            return true;
        }

        public void markAs(int as) {
            if (res != 0) {
                if (res != as) throw new RuntimeException();
                return;
            }
            res = as;
            for (Teacher t : conflicts) {
                t.markAs(3 - as);
            }
        }
    }

    static class Component {
        Teacher root;
        int l1;
        int r1;
        int l2;
        int r2;
        int insideMask;

        public void markAs(int as) {
            root.markAs(as);
        }
    }

    static class Event {
        int when;
        Component which;
        int compIndex;

        public Event(int when, Component which, int compIndex) {
            this.when = when;
            this.which = which;
            this.compIndex = compIndex;
        }
    }

    static class SetTrackerWithMax {
        TreeMap<Integer, Integer> counts = new TreeMap<>();

        public void add(int x) {
            Integer old = counts.get(x);
            if (old == null)
                counts.put(x, 1);
            else
                counts.put(x, old + 1);
        }

        public void remove(int x) {
            int v = counts.get(x);
            if (v == 1)
                counts.remove(x);
            else
                counts.put(x, v - 1);
        }

        int getMax() {
            return counts.lastKey();
        }
    }

    static class Magic {
        int numImpossible;
        SetTrackerWithMax lefts = new SetTrackerWithMax();
        SetTrackerWithMax negativeRights = new SetTrackerWithMax();

        public Magic(int totalComponents) {
            numImpossible = totalComponents;
        }

        private void addSegment(int left, int right) {
            lefts.add(left);
            negativeRights.add(-right);
        }

        private void removeSegment(int left, int right) {
            lefts.remove(left);
            negativeRights.remove(-right);
        }

        public void addComponent(Component comp) {
            if (comp.insideMask == 0) {
                ++numImpossible;
            } else if (comp.insideMask == 6) {
                if (comp.r1 > comp.r2) {
                    addSegment(comp.l1, comp.r1);
                } else {
                    addSegment(comp.l2, comp.r2);
                }
            } else if (comp.insideMask == 2) {
                addSegment(comp.l2, comp.r2);
            } else if (comp.insideMask == 4) {
                addSegment(comp.l1, comp.r1);
            } else {
                throw new RuntimeException();
            }
        }

        public void removeComponent(Component comp) {
            if (comp.insideMask == 0) {
                --numImpossible;
            } else if (comp.insideMask == 6) {
                if (comp.r1 > comp.r2) {
                    removeSegment(comp.l1, comp.r1);
                } else {
                    removeSegment(comp.l2, comp.r2);
                }
            } else if (comp.insideMask == 2) {
                removeSegment(comp.l2, comp.r2);
            } else if (comp.insideMask == 4) {
                removeSegment(comp.l1, comp.r1);
            } else {
                throw new RuntimeException();
            }
        }

        public void markComponent(Component comp) {
            if (comp.insideMask == 0) {
                throw new RuntimeException();
            } else if (comp.insideMask == 6) {
                if (comp.r1 > comp.r2) {
                    comp.markAs(2);
                } else {
                    comp.markAs(1);
                }
            } else if (comp.insideMask == 2) {
                comp.markAs(1);
            } else if (comp.insideMask == 4) {
                comp.markAs(2);
            } else {
                throw new RuntimeException();
            }
        }
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int t = in.nextInt();
        int T = in.nextInt();
        int n = in.nextInt();
        int m = in.nextInt();
        Teacher[] teachers = new Teacher[n];
        for (int i = 0; i < n; ++i) {
            teachers[i] = new Teacher();
            teachers[i].l = in.nextInt();
            teachers[i].r = in.nextInt();
        }
        for (int i = 0; i < m; ++i) {
            Teacher a = teachers[in.nextInt() - 1];
            Teacher b = teachers[in.nextInt() - 1];
            a.conflicts.add(b);
            b.conflicts.add(a);
        }

        List<Component> components = new ArrayList<>(teachers.length);
        for (Teacher teacher : teachers) if (teacher.kind == 0) {
            Component c = new Component();
            c.l1 = 0;
            c.r1 = T;
            c.l2 = 0;
            c.r2 = T;
            c.root = teacher;
            if (!teacher.buildComponent(c, 1)) {
                out.println("IMPOSSIBLE");
                return;
            }
            if (c.l1 > c.r1 || c.l2 > c.r2) {
                out.println("IMPOSSIBLE");
                return;
            }
            components.add(c);
        }

        List<Event> events = new ArrayList<>(4 * components.size());
        for (Component c : components) {
            events.add(new Event(c.l1, c, 1));
            events.add(new Event(c.r1 + 1, c, 1));
            events.add(new Event(c.l2, c, 2));
            events.add(new Event(c.r2 + 1, c, 2));
        }
        Collections.sort(events, new Comparator<Event>() {
            public int compare(Event o1, Event o2) {
                return o1.when - o2.when;
            }
        });

        Magic magic = new Magic(components.size());

        int ptr = 0;
        while (ptr < events.size()) {
            int count = events.get(ptr).when;
            while (ptr < events.size() && events.get(ptr).when == count) {
                Event cur = events.get(ptr++);
                magic.removeComponent(cur.which);
                cur.which.insideMask ^= (1 << cur.compIndex);
                magic.addComponent(cur.which);
            }

            if (magic.numImpossible == 0) {
                int nextAt = events.get(ptr).when;
                int oleft = magic.lefts.getMax();
                int oright = -magic.negativeRights.getMax();
                if (oleft <= oright) {
                    if (count + oleft <= T && nextAt - 1 + oright >= t) {
                        out.println("POSSIBLE");
                        int n1 = count;
                        int n2 = oleft;
                        if (n1 + n2 < t) {
                            int extra = t - n1 - n2;
                            int by = Math.min(extra, nextAt - 1 - count);
                            extra -= by;
                            n1 += by;
                            by = Math.min(extra, oright - oleft);
                            extra -= by;
                            n2 += by;
                            if (extra != 0) throw new RuntimeException();
                        }
                        if (n1 + n2 < t || n1 + n2 > T) throw new RuntimeException();
                        out.println(n1 + " " + n2);
                        for (Component c : components) {
                            magic.markComponent(c);
                        }
                        for (Teacher teacher : teachers) {
                            out.print(teacher.res);
                        }
                        out.println();
                        return;
                    }
                }
            }
        }
        out.println("IMPOSSIBLE");
    }
}

class InputReader {
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