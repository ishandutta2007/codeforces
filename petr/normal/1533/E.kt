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
        val solver = EUkomplektovanieShakhmatnoiKomandi()
        solver.solve(1, `in`, out)
        out.close()
    }

    internal class EUkomplektovanieShakhmatnoiKomandi {
        fun solve(testNumber: Int, `in`: InputReader, out: PrintWriter) {
            val n = `in`.nextInt()
            val a = IntArray(n)
            val b = IntArray(n + 1)
            for (i in a.indices) a[i] = `in`.nextInt()
            for (i in b.indices) b[i] = `in`.nextInt()
            val random = Random(75417543154351L + System.currentTimeMillis())
            shuffle(a, random)
            shuffle(b, random)
            Arrays.sort(a)
            Arrays.sort(b)
            val pref = IntArray(a.size + 1)
            val suf = IntArray(a.size + 1)
            pref[0] = (-2e9).toInt()
            suf[0] = (-2e9).toInt()
            for (i in a.indices) {
                pref[i + 1] = Math.max(pref[i], b[i] - a[i])
            }
            for (i in a.indices) {
                suf[i + 1] = Math.max(suf[i], b[b.size - 1 - i] - a[a.size - 1 - i])
            }
            val m = `in`.nextInt()
            for (i in 0 until m) {
                val c = `in`.nextInt()
                var pos = Arrays.binarySearch(a, c)
                if (pos < 0) {
                    pos = -(pos + 1)
                }
                out.print(Math.max(pref[pos], Math.max(suf[a.size - pos], b[pos] - c)).toString() + " ")
            }
            out.println()
        }

        private fun shuffle(a: IntArray, random: Random) {
            for (i in a.indices) {
                val j = random.nextInt(i + 1)
                val t = a[i]
                a[i] = a[j]
                a[j] = t
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