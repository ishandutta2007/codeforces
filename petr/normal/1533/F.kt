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
        val solver = FRazbienieDvoichnoiStroki()
        solver.solve(1, `in`, out)
        out.close()
    }

    internal class FRazbienieDvoichnoiStroki {
        fun solve(testNumber: Int, `in`: InputReader, out: PrintWriter) {
            val s = `in`.next()
            val n = s.length
            val p0 = IntArray(n * 2 + 5)
            Arrays.fill(p0, n)
            var n0 = 0
            val p1 = IntArray(n * 2 + 5)
            Arrays.fill(p1, n)
            var n1 = 0
            val n0s = IntArray(n)
            val n1s = IntArray(n)
            for (i in 0 until s.length) {
                n0s[i] = n0
                n1s[i] = n1
                if (s[i] == '0') p0[n0++] = i else p1[n1++] = i
            }
            for (k in 1..n) {
                var at = 0
                var res = 0
                while (at < n) {
                    ++res
                    at = Math.max(p0[n0s[at] + k], p1[n1s[at] + k])
                }
                out.print("$res ")
            }
            out.println()
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

        init {
            reader = BufferedReader(InputStreamReader(stream), 32768)
            tokenizer = null
        }
    }
}