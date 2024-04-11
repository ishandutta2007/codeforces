import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

/**
 * To be documented..
 * Date: May 4, 2011
 * Time: 8:57:59 AM
 *
 * @author Pavel Mavrin
 */
public class E {

    private void solve() throws IOException {
        int n = nextInt();
        int[] f = new int[n];
        int[] s = new int[n];
        for (int i = 0; i < n; i++) {
            f[i] = nextInt() - 1;
            s[i] = nextInt();
        }
        int[] mark = new int[n];
        Node[] nodes = new Node[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node(i, s[i]);
        }

        List<List<Node>> cycles = new ArrayList<List<Node>>();
        for (int i = 0; i < n; i++) {
            if (mark[i] == 0) {
                int j = i;
                while (mark[j] == 0) {
                    mark[j] = 1;
                    j = f[j];
                }
                if (mark[j] == 1) {
                    List<Node> cycle = new ArrayList<Node>();
                    while (mark[j] == 1) {
                        cycle.add(nodes[j]);
                        mark[j] = 2;
                        j = f[j];
                    }
                    cycles.add(cycle);
                }
                j = i;
                while (mark[j] == 1) {
                    mark[j] = 3;
                    j = f[j];
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (mark[i] == 3) {
                nodes[f[i]].children.add(nodes[i]);
            }
        }

        List<Pair> result = new ArrayList<Pair>();

        for (List<Node> cycle : cycles) {
            for (Node node : cycle) {
                node.precalc();
            }
            Res[] d = new Res[cycle.size()];
            int[] pp = new int[cycle.size()];
            d[0] = cycle.get(0).best;
            for (int i = 1; i < cycle.size(); i++) {
                d[i] = cycle.get(i).best.sum(d[i - 1]);
                Res res = cycle.get(i).bestEmpty.sum(cycle.get(i - 1).bestEmpty);
                if (i > 1) {
                    res = res.sum(d[i - 2]);
                }
                res = res.sum(new Res(1, cycle.get(i).sex == cycle.get(i - 1).sex ? 0 : 1));
                if (res.compareTo(d[i]) > 0) {
                    d[i] = res;
                    pp[i] = 1;
                }
            }
            List<Node> cycle2 = new ArrayList<Node>();
            for (int i = 1; i < cycle.size(); i++) cycle2.add(cycle.get(i));
            cycle2.add(cycle.get(0));
            Res rr = d[cycle.size() -1];
            int[] pp2 = new int[cycle.size()];
            d[0] = cycle2.get(0).best;
            for (int i = 1; i < cycle.size(); i++) {
                d[i] = cycle2.get(i).best.sum(d[i - 1]);
                Res res = cycle2.get(i).bestEmpty.sum(cycle2.get(i - 1).bestEmpty);
                if (i > 1) {
                    res = res.sum(d[i - 2]);
                }
                res = res.sum(new Res(1, cycle2.get(i).sex == cycle2.get(i - 1).sex ? 0 : 1));
                if (res.compareTo(d[i]) > 0) {
                    d[i] = res;
                    pp2[i] = 1;
                }
            }
            Res rr2 = d[cycle.size() -1];
            if (rr2.compareTo(rr) > 0) {
                pp = pp2;
                cycle = cycle2;
            }
            int j = cycle.size() - 1;
            while (j >= 0) {
                if (pp[j] == 1) {
                    result.add(new Pair(cycle.get(j).id, cycle.get(j - 1).id));
                    cycle.get(j).addEmpty(result);
                    cycle.get(j - 1).addEmpty(result);
                    j -= 2;
                } else {
                    cycle.get(j).add(result);
                    j--;
                }
            }

        }

        int sx = 0;

        for (Pair pair : result) {
            if (s[pair.a] != s[pair.b]) sx++;
        }
        out.println(result.size() + " " + sx);

        for (Pair pair : result) {
            out.println((pair.a + 1) + " " + (pair.b + 1));
        }


        //To change body of created methods use File | Settings | File Templates.
    }

    class Pair {
        int a, b;

        Pair(int a, int b) {
            this.a = a;
            this.b = b;
        }
    }

    class Node {
        int id;
        int sex;
        List<Node> children = new ArrayList<Node>();
        Res best;
        Res bestEmpty;
        Node bestTake;

        Node(int id, int sex) {
            this.id = id;
            this.sex = sex;
        }

        public void precalc() {
            bestEmpty = new Res(0, 0);
            for (Node child : children) {
                child.precalc();
                bestEmpty.pairs += child.best.pairs;
                bestEmpty.sexpairs += child.best.sexpairs;
            }
            best = bestEmpty;
            for (Node child : children) {
                Res res = new Res(
                        bestEmpty.pairs - child.best.pairs + child.bestEmpty.pairs + 1,
                        bestEmpty.sexpairs - child.best.sexpairs + child.bestEmpty.sexpairs + (sex == child.sex ? 0 : 1)
                );
                if (res.compareTo(best) > 0) {
                    best = res;
                    bestTake = child;
                }
            }
        }

        public void addEmpty(List<Pair> result) {
            for (Node child : children) {
                child.add(result);
            }
        }

        public void add(List<Pair> result) {
            if (bestTake == null) {
                addEmpty(result);
            } else {
                result.add(new Pair(this.id, bestTake.id));
                for (Node child : children) {
                    if (child == bestTake) {
                        child.addEmpty(result);
                    } else {
                        child.add(result);
                    }
                }
            }
        }
    }

    class Res implements Comparable<Res> {
        int pairs;
        int sexpairs;

        Res(int pairs, int sexpairs) {
            this.pairs = pairs;
            this.sexpairs = sexpairs;
        }

        public int compareTo(Res res) {
            if (res.pairs != pairs) {
                return pairs - res.pairs;
            }
            return sexpairs - res.sexpairs;
        }

        public Res sum(Res res) {
            return new Res(pairs + res.pairs, sexpairs + res.sexpairs);
        }
    }

    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }


    public static void main(String[] args) throws IOException {
        new E().run();
    }

    private void run() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
        br.close();
    }

}