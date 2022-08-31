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
        val solver = DPoiskStrok()
        solver.solve(1, `in`, out)
        out.close()
    }

    internal class DPoiskStrok {
        fun solve(testNumber: Int, `in`: InputReader, out: PrintWriter) {
            val n = `in`.nextInt()
            val m = `in`.nextInt()
            val counts: MutableMap<String, Int> = HashMap()
            for (i in 0 until n) {
                val s = `in`.next()
                val old = counts[s]
                if (old == null) counts[s] = 1 else counts[s] = old + 1
            }
            val q = `in`.nextInt()
            val seen: MutableSet<String> = HashSet()
            for (qi in 0 until q) {
                val t = `in`.next()
                seen.clear()
                var res = 0
                for (i in 0 until t.length) {
                    val cur = t.substring(0, i) + t.substring(i + 1)
                    if (!seen.add(cur)) continue
                    val got = counts[cur]
                    if (got != null) res += got
                }
                out.println(res)
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