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
        val solver = CSladosti()
        val testCount = `in`.next().toInt()
        for (i in 1..testCount) solver.solve(i, `in`, out)
        out.close()
    }

    internal class CSladosti {
        fun solve(testNumber: Int, `in`: InputReader, out: PrintWriter) {
            val n = `in`.nextInt()
            val k = `in`.nextInt()
            val ok = `in`.next().toCharArray()
            val alive = BooleanArray(n)
            Arrays.fill(alive, true)
            var countOk = 0
            for (x in ok) if (x == '1') ++countOk
            var res = 0
            var at = 0
            while (countOk > 0) {
                ++res
                alive[at] = false
                if (ok[at] == '1') --countOk
                if (countOk == 0) break
                for (step in 0 until k) {
                    do {
                        ++at
                        if (at >= n) at = 0
                    } while (!alive[at])
                }
            }
            out.println(res)
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