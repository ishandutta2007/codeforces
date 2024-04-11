import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Macros implements Runnable {
    static enum Op {
        NONE,
        ADDITIVE,
        MULTIPLICATIVE
    }

    static class Part {
        Op op;
        boolean fromDef;
    }

    static class Definition {
        Op op;
        boolean unsafe;
    }

    String line;
    int pos;
    boolean curUnsafe;
    Map<String, Definition> defs;

    private void solve() throws IOException {
        int n = nextInt();
        defs = new HashMap<String, Definition>();
        for (int i = 0; i < n; ++i) {
            line = reader.readLine() + "@";
            pos = line.indexOf("define") + 6;
            while (line.charAt(pos) <= ' ')
                ++pos;
            int pos2 = pos;
            while (line.charAt(pos2) >= 'a' && line.charAt(pos2) <= 'z' || line.charAt(pos2) >= 'A' && line.charAt(pos2) <= 'Z')
                ++pos2;
            String name = line.substring(pos, pos2);
            pos = pos2;
            curUnsafe = false;
            Op op = parseExpr().op;
            Definition def = new Definition();
            def.op = op;
            def.unsafe = curUnsafe;
            defs.put(name, def);
            if (nextNonSpace() != '@')
                throw new RuntimeException();
        }
        curUnsafe = false;
        line = reader.readLine() + "@";
        pos = 0;
        parseExpr();
        if (nextNonSpace() != '@')
            throw new RuntimeException();
        if (curUnsafe) {
            writer.println("Suspicious");
        } else {
            writer.println("OK");
        }
    }

    char nextNonSpace() {
        while (line.charAt(pos) <= ' ')
            ++pos;
        return line.charAt(pos);
    }

    private Part parseExpr() {
        Part res = parseAddend();
        while (nextNonSpace() == '-' || nextNonSpace() == '+') {
            char ch = nextNonSpace();
            ++pos;
            Part res2 = parseAddend();
            if (res2.op == Op.ADDITIVE && res2.fromDef && ch == '-') {
                curUnsafe = true;
            }
            if (res.op == Op.ADDITIVE && res.fromDef || res2.op == Op.ADDITIVE && res2.fromDef) {
                res.fromDef = true;
            } else {
                res.fromDef = false;
            }
            res.op = Op.ADDITIVE;
        }
        return res;
    }

    private Part parseAddend() {
        Part res = parseMultiplier();
        while (nextNonSpace() == '*' || nextNonSpace() == '/') {
            char ch = nextNonSpace();
            ++pos;
            Part res2 = parseMultiplier();
            if (res.op == Op.ADDITIVE && res.fromDef || res2.op == Op.ADDITIVE && res2.fromDef || (res2.op == Op.MULTIPLICATIVE && res2.fromDef && ch == '/')) {
                curUnsafe = true;
            }
            if (res2.op == Op.MULTIPLICATIVE && res2.fromDef || res.op == Op.MULTIPLICATIVE && res.fromDef) {
                res.fromDef = true;
            } else {
                res.fromDef = false;
            }
            res.op = Op.MULTIPLICATIVE;
        }
        return res;
    }

    private Part parseMultiplier() {
        char ch = nextNonSpace();
        if (ch == '(') {
            ++pos;
            parseExpr();
            nextNonSpace();
            ++pos;
            Part part = new Part();
            part.op = Op.NONE;
            part.fromDef = false;
            return part;
        } else {
            int pos2 = pos;
            while (line.charAt(pos2) >= 'a' && line.charAt(pos2) <= 'z' || line.charAt(pos2) >= 'A' && line.charAt(pos2) <= 'Z' || line.charAt(pos2) >= '0' && line.charAt(pos2) <= '9')
                ++pos2;
            String name = line.substring(pos, pos2);
            pos = pos2;
            if (defs.containsKey(name)) {
                if (defs.get(name).unsafe)
                    curUnsafe = true;
                Part p = new Part();
                p.op = defs.get(name).op;
                p.fromDef = true;
                return p;
            } else {
                Part part = new Part();
                part.op = Op.NONE;
                part.fromDef = false;
                return part;
            }
        }
    }


    public static void main(String[] args) {
        new Macros().run();
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