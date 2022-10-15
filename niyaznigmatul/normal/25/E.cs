using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Main {
    class Program {

        void solve() {
            string[] s = new string[3];
            for (int i = 0; i < 3; i++) {
                s[i] = sc.next();
            }            
            int[,] f = new int[3, 3];
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (i == j) {
                        continue;
                    }
                    int[] p = prefixFunction(s[i] + "#" + s[j]);
                    f[j, i] = p[p.Length - 1] + 1;
                    for (int k = 0; k < p.Length; k++) {
                        if (p[k] == s[i].Length - 1) {
                            s[i] = "";
                            f[j, i] = 0;
                            break;
                        }
                    }
                }
            }
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (f[i, j] > s[i].Length || f[i, j] > s[j].Length) {
                        f[i, j] = 0;
                    }
                }
            }
            int ans = Int32.MaxValue;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (i == j) {
                        continue;
                    }
                    for (int k = 0; k < 3; k++) {
                        if (i == k || j == k) {
                            continue;
                        }
                        int got = s[i].Length + s[j].Length + s[k].Length - f[i, j] - f[j, k];
                        ans = Math.Min(ans, got);
                    }
                }
            }
            output.WriteLine(ans);
        }

        static int[] prefixFunction(string s) {
            int[] p = new int[s.Length];
            p[0] = -1;
            int k = -1;
            for (int i = 1; i < s.Length; i++) {
                while (k > -1 && s[k + 1] != s[i]) {
                    k = p[k];
                }
                if (s[k + 1] == s[i]) {
                    k++;
                }
                p[i] = k;
            }            
            return p;
        }

        public abstract class InputReader {
            protected char[] buf;
            protected int current;
            protected bool isFinished;

            public InputReader() {
                buf = new char[10024];
                current = buf.Length;
            }

            public abstract int read();

            public int nextInt() {
                int c = read();
                while (c <= 32 && c >= 0) {
                    c = read();
                }
                int sgn = 1;
                if (c == '-') {
                    sgn = -1;
                    c = read();
                }
                if (c < '0' || c > '9') {
                    throw new Exception("digit expected " + (char)c
                            + " found");
                }
                int ret = 0;
                while (c >= '0' && c <= '9') {
                    ret = ret * 10 + (c - '0');
                    c = read();
                }
                if (c == -1) {
                    isFinished = true;
                }
                if (c > 32) {
                    throw new Exception("space character expected "
                            + (char)c + " found");
                }
                return ret * sgn;
            }

            public long nextLong() {
                int c = read();
                while (c <= 32 && c >= 0) {
                    c = read();
                }
                int sgn = 1;
                if (c == '-') {
                    sgn = -1;
                    c = read();
                }
                if (c < '0' || c > '9') {
                    throw new Exception("digit expected " + (char)c
                            + " found");
                }
                long ret = 0;
                while (c >= '0' && c <= '9') {
                    ret = ret * 10 + (c - '0');
                    c = read();
                }
                if (c == -1) {
                    isFinished = true;
                }
                if (c > 32) {
                    throw new Exception("space character expected "
                            + (char)c + " found");
                }
                return ret * sgn;
            }

            public string next() {
                int c = read();
                while (c <= 32 && c >= 0) {
                    c = read();
                }
                StringBuilder sb = new StringBuilder();
                while (c > 32) {
                    sb.Append((char)(c));
                    c = read();
                }
                if (c == -1) {
                    isFinished = true;
                }
                return sb.ToString();
            }

            public bool isFinishedFunction() {
                return isFinished;
            }
            
        }


        public class StreamInputReader : InputReader {
            private StreamReader stream;

            public StreamInputReader(StreamReader stream)
                : base() {
                this.stream = stream;
            }

            override public int read() {
                if (current == buf.Length) {
                    if (stream.ReadBlock(buf, 0, buf.Length) == 0) {
                        return -1;
                    }
                    current = 0;
                }
                return buf[current++];
            }
        }

        InputReader sc;
        StreamWriter output;

        public static void Main(string[] args) {
            new Program().run();
        }

        public void run() {
            sc = new StreamInputReader(new StreamReader(Console.OpenStandardInput()));
            output = new StreamWriter(Console.OpenStandardOutput());
            solve();
            output.Close();
        }        
    }
}