import java.io.*
import java.util.*

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
object program {
    @JvmStatic
    fun main(args: Array<String>) {
        val inputStream = System.`in`
        val outputStream: OutputStream = System.out
        val `in` = InputReader(inputStream)
        val out = PrintWriter(outputStream)
        val solver = GKartaBiomov()
        val testCount = `in`.next().toInt()
        for (i in 1..testCount) solver.solve(i, `in`, out)
        out.close()
    }

    internal class GKartaBiomov {
        private var seq: IntArray = IntArray(0);
        private var id: Array<IntArray> = Array(0) { IntArray(0) };
        var mark: Array<BooleanArray> = Array(0) { BooleanArray(0) };
        private var m = 0
        private var n = 0
        var pos = 0
        fun solve(testNumber: Int, `in`: InputReader, out: PrintWriter) {
            n = `in`.nextInt()
            m = `in`.nextInt()
            id = Array(n) { IntArray(m) }
            mark = Array(n) { BooleanArray(m) }
            var count = 0
            var si = -1
            var sj = -1
            for (i in 0 until n) {
                for (j in 0 until m) {
                    id[i][j] = `in`.nextInt()
                    if (id[i][j] > 0) {
                        ++count
                        si = i
                        sj = j
                    }
                }
            }
            seq = IntArray(2 * count - 1)
            pos = 0
            dfs(si, sj)
            if (pos != seq.size) {
                out.println(-1)
                return
            }
            out.println("$count $count")
            for (i in 0 until count) {
                for (j in 0 until count) {
                    out.print(seq[i + j].toString() + " ")
                }
                out.println()
            }
        }

        private fun dfs(i: Int, j: Int) {
            mark[i][j] = true
            seq[pos++] = id[i][j]
            for (ni in i - 1..i + 1) for (nj in j - 1..j + 1) if (Math.abs(ni - i) + Math.abs(nj - j) == 1) {
                if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                    if (id[ni][nj] > 0 && !mark[ni][nj]) {
                        dfs(ni, nj)
                        seq[pos++] = id[i][j]
                    }
                }
            }
        }
    }

    internal class InputReader(stream: InputStream?) {
        var reader: BufferedReader
        var tokenizer: StringTokenizer?
        operator fun next(): String {
            while (tokenizer == null || !tokenizer!!.hasMoreTokens()) {
                tokenizer = try {
                    StringTokenizer(reader.readLine())
                } catch (e: IOException) {
                    throw RuntimeException(e)
                }
            }
            return tokenizer!!.nextToken()
        }

        fun nextInt(): Int {
            return next().toInt()
        }

        init {
            reader = BufferedReader(InputStreamReader(stream), 32768)
            tokenizer = null
        }
    }
}