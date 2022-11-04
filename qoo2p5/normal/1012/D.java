import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class swap_prefixes_av_n {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        SwapPrefixesDp solver = new SwapPrefixesDp();
        solver.solve(1, in, out);
        out.close();
    }

    static class SwapPrefixesDp {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            String s = in.next(), t = in.next();
            List<Integer> ans1 = solve("a" + s, "b" + t);
            List<Integer> ans2 = solve("b" + s, "a" + t);
            if (ans1.size() > ans2.size()) {
                ans1 = ans2;
            }
            out.println(ans1.size() / 2);
            for (int i = 0; i < ans1.size(); i += 2) {
                out.println(ans1.get(i) + " " + ans1.get(i + 1));
            }
        }

        private void makeSwap(List<Integer> realAns, List<Pair> compressedS, List<Pair> compressedT, int lenS, int lenT) {
            List<Pair> newS = new ArrayList<>();
            List<Pair> newT = new ArrayList<>();

            int realLenS = 0, realLenT = 0;
            for (int i = 0; i < lenS; i++) {
                realLenS += compressedS.get(i).count;
            }
            for (int i = 0; i < lenT; i++) {
                realLenT += compressedT.get(i).count;
            }
            realAns.add(realLenS - 1);
            realAns.add(realLenT - 1);
            concatLists(compressedS, compressedT, lenS, lenT, newS);
            concatLists(compressedT, compressedS, lenT, lenS, newT);
            compressedS.clear();
            compressedS.addAll(newS);
            compressedT.clear();
            compressedT.addAll(newT);
        }

        private void concatLists(List<Pair> compressedS, List<Pair> compressedT, int lenS, int lenT, List<Pair> newS) {
            newS.addAll(compressedT.subList(0, lenT));
            newS.addAll(compressedS.subList(lenS, compressedS.size()));
            if (lenT < newS.size() && newS.get(lenT - 1).ch == newS.get(lenT).ch) {
                newS.get(lenT - 1).count += newS.get(lenT).count;
                newS.remove(lenT);
            }
        }

        private List<Integer> solve(String s, String t) {
            List<Pair> compressedS = compress(s);
            List<Pair> compressedT = compress(t);
            if (compressedS.size() == 1 && compressedT.size() == 1) {
                return new ArrayList<>();
            }
            int curI = compressedS.size(), curJ = compressedT.size();

            int bestI = -1, bestJ = -1;
            int bestCost = Integer.MAX_VALUE;

            for (int lenI = 1; lenI <= compressedS.size(); lenI++) {
                for (int lenJ = 1; lenJ <= compressedT.size(); lenJ++) {
                    if (lenI % 2 != lenJ % 2) {
                        continue;
                    }
                    if (lenI > 3 && lenJ > 3) {
                        break;
                    }
                    int nextI = lenJ + (curI - lenI) - ((curI != lenI && lenJ % 2 == lenI % 2) ? 1 : 0);
                    int nextJ = lenI + (curJ - lenJ) - ((curJ != lenJ && lenJ % 2 == lenI % 2) ? 1 : 0);

                    int cost = 1 + Math.max(nextI, nextJ);
                    if (cost < bestCost) {
                        bestCost = cost;
                        bestI = lenI;
                        bestJ = lenJ;
                    }
                }
            }

            List<Integer> ans = new ArrayList<>();
            makeSwap(ans, compressedS, compressedT, bestI, bestJ);

            int nextI = compressedS.size(), nextJ = compressedT.size();

            int prefixA = 0, prefixB = 0;
            for (int i = 0; i < Math.max(nextI, nextJ) - 1; i++) {
                if (i % 2 == 0) {
                    prefixA += i >= compressedS.size() ? 0 : compressedS.get(i).count;
                    prefixB += i >= compressedT.size() ? 0 : compressedT.get(i).count;
                    ans.add(prefixA - 1);
                    ans.add(prefixB - 1);
                } else {
                    prefixA += i >= compressedT.size() ? 0 : compressedT.get(i).count;
                    prefixB += i >= compressedS.size() ? 0 : compressedS.get(i).count;
                    ans.add(prefixB - 1);
                    ans.add(prefixA - 1);
                }
            }

            return ans;
        }

        private List<Pair> compress(String s) {
            List<Pair> result = new ArrayList<>();
            for (int i = 0; i < s.length(); ) {
                int j = i;
                while (j < s.length() && s.charAt(i) == s.charAt(j)) {
                    j++;
                }
                result.add(new Pair(s.charAt(i), j - i));
                i = j;
//                System.err.println(result);
            }
            return result;
        }

        class Pair {
            char ch;
            int count;

            public Pair(char ch, int count) {
                this.ch = ch;
                this.count = count;
            }

            @Override
            public String toString() {
                return "Pair{" +
                        "ch=" + ch +
                        ", count=" + count +
                        '}';
            }
        }

    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
        }

        public String next() {
            while (st == null || !st.hasMoreElements()) {
                String line = null;
                try {
                    line = br.readLine();
                } catch (IOException e) {
                }
                st = new StringTokenizer(line);
            }
            return st.nextToken();
        }

    }
}