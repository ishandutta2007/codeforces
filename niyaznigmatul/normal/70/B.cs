using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Main {
    class Program {

        const int MOD = 1000003;

        void solve() {
            int n = Int32.Parse(Console.ReadLine());
            string s = Console.ReadLine();
            string[] t = s.Split(new char[] { '.', '?', '!'});
            for (int i = 0; i < t.Length; i++) {
                t[i] = t[i].Trim();
            }
            int ans = 1;
            int got = -1;
            for (int i = 0; i < t.Length; i++) {
                if (t[i].Length == 0) {
                    continue;
                }
                if (got + t[i].Length + 2 > n) {
                    ans++;
                    got = -1;
                }
                got += t[i].Length + 2;
                if (got > n) {
                    output.WriteLine("Impossible");
                    return;
                }
            }
            output.WriteLine(ans);
        }


        public abstract class InputReader {
            protected char[] buf;
            protected int current;
            protected bool isFinished;

            public InputReader() {
                buf = new char[1024];
                current = 1024;
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
  //          sc = new StreamInputReader(new StreamReader(Console.OpenStandardInput()));
            output = new StreamWriter(Console.OpenStandardOutput());
            solve();
            output.Close();
        }        
    }
}