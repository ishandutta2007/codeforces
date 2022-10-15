using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Main {
    class Program {

        static int[] primes;
        
        void solve() {
            bool[] p = new bool[1000];
            int count = p.Length - 2;
            for (int i = 2; i * i < p.Length; i++) {
                if (!p[i]) {
                    for (int j = i * i; j < p.Length; j += i) {
                        if (!p[j]) {
                            p[j] = true;
                            --count;
                        }
                    }
                }
            }
            primes = new int[count];
            for (int i = 2, j = 0; i < p.Length; i++) {
                if (!p[i]) {
                    primes[j++] = i;
                }
            }
            int n = sc.nextInt();
            if (n == 1) {
                output.WriteLine(1);
            } else {
                output.WriteLine(go(0, n, 100, 1));
            }
        }
        


        static long go(int x, int n, int last, long cur) {            
            if (n == 1) {
                return cur;
            }
            long ret = Int64.MaxValue;
            for (int i = 1; i <= last; i++) {
                if (cur >= Int64.MaxValue / primes[x]) {
                    break;
                }
                cur *= primes[x];
                if (n % (i + 1) == 0) {
                    ret = Math.Min(ret, go(x + 1, n / (i + 1), i, cur));
                }                
            }
            return ret;
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
            sc = new StreamInputReader(new StreamReader(Console.OpenStandardInput()));
            output = new StreamWriter(Console.OpenStandardOutput());
            solve();
            output.Close();
        }        
    }
}