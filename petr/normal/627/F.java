import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
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
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            Island[] islands = new Island[n];
            Island zeroStart = null;
            for (int i = 0; i < n; ++i) {
                islands[i] = new Island(i + 1);
                islands[i].start = in.nextInt();
                if (islands[i].start == 0) zeroStart = islands[i];
            }
            Island zeroFinish = null;
            for (int i = 0; i < n; ++i) {
                islands[i].finish = in.nextInt();
                if (islands[i].finish == 0) zeroFinish = islands[i];
            }
            for (int i = 0; i < n - 1; ++i) {
                Island a = islands[in.nextInt() - 1];
                Island b = islands[in.nextInt() - 1];
                a.adj.add(b);
                b.adj.add(a);
            }
            int fixed = 0;
            for (Island island : islands) if (island.start == island.finish) ++fixed;
            int movesDone = 0;
            zeroStart.movedThrough = true;
            if (!zeroStart.comeFrom(zeroFinish, null)) throw new RuntimeException();
            while (zeroStart != zeroFinish) {
                Island isl = zeroStart.nextInHypothetical;
                if (isl.start == isl.finish) --fixed;
                zeroStart.start = isl.start;
                isl.start = 0;
                if (zeroStart.start == zeroStart.finish) ++fixed;
                if (isl.start == isl.finish) ++fixed;
                zeroStart = isl;
                zeroStart.movedThrough = true;
                ++movesDone;
            }
            if (fixed == n) {
                out.println(0 + " " + movesDone);
                return;
            }

            Island center = null;
            zeroStart.initMovedThroughDistance(null);
            outer:
            for (Island isl : islands) {
                if (isl.start != isl.finish) {
                    for (Island other : isl.adj) {
                        if (other.movedThroughDistance >= 0) {
                            center = other;
                            movesDone += 2 * other.movedThroughDistance;
                            break outer;
                        }
                    }
                }
            }
            if (center == null) {
                out.println(-1);
                return;
            }
            if (!zeroStart.comeFrom(center, null)) throw new RuntimeException();
            while (zeroStart != center) {
                Island isl = zeroStart.nextInHypothetical;
                zeroStart.start = isl.start;
                zeroStart.finish = isl.finish;
                isl.start = 0;
                isl.finish = 0;
                zeroStart = isl;
            }

            int numHands = 0;
            Island hand1End = center;
            Island hand2End = center;
            List<Island> hand1 = new ArrayList<>();
            List<Island> hand2 = new ArrayList<>();
            int totalInHands = 0;
            for (Island handStart : center.adj) {
                if (handStart.start != handStart.finish) {
                    ++numHands;
                    if (numHands > 2) {
                        out.println(-1);
                        return;
                    }
                    List<Island> hand;
                    if (numHands == 1) {
                        hand = hand1;
                    } else {
                        hand = hand2;
                    }
                    hand.add(handStart);
                    Island handEnd = handStart;
                    Island handPrev = zeroStart;
                    ++totalInHands;
                    outer3:
                    while (true) {
                        for (Island isl : handEnd.adj) {
                            if (isl != handPrev) {
                                if (isl.start != isl.finish) {
                                    hand.add(isl);
                                    handPrev = handEnd;
                                    handEnd = isl;
                                    ++totalInHands;
                                    continue outer3;
                                }
                            }
                        }
                        break;
                    }
                    if (numHands == 1) hand1End = handEnd;
                    else hand2End = handEnd;
                }
            }
            if (fixed + totalInHands != n) {
                out.println(-1);
                return;
            }

            zeroStart.cyclePos = 0;
            for (int i = 0; i < hand2.size(); ++i) {
                hand2.get(i).cyclePos = 1 + hand1.size() + hand2.size() - i;
            }
            int[] cycleStart = new int[hand1.size() + hand2.size()];
            int[] cycleFinish = new int[hand1.size() + hand2.size()];
            for (int i = 0; i < hand1.size(); ++i) {
                cycleStart[i] = hand1.get(i).start;
                cycleFinish[i] = hand1.get(i).finish;
            }
            for (int i = 0; i < hand2.size(); ++i) {
                cycleStart[cycleStart.length - 1 - i] = hand2.get(i).start;
                cycleFinish[cycleFinish.length - 1 - i] = hand2.get(i).finish;
            }
            int offset;
            for (offset = 0; offset < cycleFinish.length; ++offset) {
                if (cycleFinish[offset] == cycleStart[0]) break;
            }
            if (offset >= cycleFinish.length) {
                throw new RuntimeException();
            }
            for (int i = 0; i < cycleFinish.length; ++i) {
                if (cycleFinish[(i + offset) % cycleFinish.length] != cycleStart[i]) {
                    out.println(-1);
                    return;
                }
            }
            int extra1 = 0;
            int extra2 = 0;
            for (Island isl : hand1)
                if (isl.movedThrough) ++extra2;
                else break;
            for (Island isl : hand2)
                if (isl.movedThrough) ++extra1;
                else break;
            long cycleCost = Math.min(Math.abs((1 + cycleStart.length) * (long) offset - extra1) - extra1, Math.abs((1 + cycleStart.length) * (long) (cycleStart.length - offset) - extra2) - extra2) + movesDone;
            out.println(Math.min(hand1End.index, hand2End.index) + " " + Math.max(hand1End.index, hand2End.index) + " " + (cycleCost));
        }

        static class Island {
            int index;
            int start;
            int finish;
            boolean movedThrough = false;
            int movedThroughDistance = -1;
            List<Island> adj = new ArrayList<>(1);
            int cyclePos;
            Island nextInHypothetical = null;

            public Island(int index) {
                this.index = index;
            }

            public boolean comeFrom(Island zeroStart, Island parent) {
                if (this == zeroStart) return true;
                for (Island isl : adj) {
                    if (isl != parent) {
                        if (isl.comeFrom(zeroStart, this)) {
                            nextInHypothetical = isl;
                            return true;
                        }
                    }
                }
                return false;
            }

            public void initMovedThroughDistance(Island parent) {
                if (start != finish) return;
                if (movedThrough) {
                    movedThroughDistance = 0;
                } else {
                    movedThroughDistance = parent.movedThroughDistance + 1;
                }
                for (Island isl : adj) {
                    if (isl != parent) {
                        isl.initMovedThroughDistance(this);
                    }
                }
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