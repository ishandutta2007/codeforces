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
        val solver = HPodmatritsi()
        solver.solve(1, `in`, out)
        out.close()
    }

    internal class HPodmatritsi {
        fun solve(testNumber: Int, `in`: InputReader, out: PrintWriter) {
            val height = `in`.nextInt()
            val width = `in`.nextInt()
            val data = arrayOfNulls<String>(height)
            for (r in 0 until height) {
                data[r] = `in`.next()
            }
            val count = LongArray(1 shl 5)
            val h = IntArray(width)
            val stack = IntArray(width)
            for (s in 1 until (1 shl 5)) {
                Arrays.fill(h, 0)
                for (r in 0 until height) {
                    var sp = 0
                    var total: Long = 0
                    for (c in 0 until width) {
                        if (s and (1 shl data[r]!![c] - 'A') != 0) {
                            ++h[c]
                        } else {
                            h[c] = 0
                        }
                        while (sp > 0 && h[stack[sp - 1]] >= h[c]) {
                            val before = if (sp - 2 >= 0) stack[sp - 2] else -1
                            total -= h[stack[sp - 1]] * (stack[sp - 1] - before).toLong()
                            --sp
                        }
                        stack[sp++] = c
                        run {
                            val before = if (sp - 2 >= 0) stack[sp - 2] else -1
                            total += h[stack[sp - 1]] * (stack[sp - 1] - before).toLong()
                        }
                        count[s] += total
                    }
                }
            }
            for (a in 0..4) {
                for (s in 0 until (1 shl 5)) {
                    if (s and (1 shl a) == 0) {
                        count[s or (1 shl a)] -= count[s]
                    }
                }
            }
            val res = LongArray(6)
            for (i in 0 until (1 shl 5)) {
                res[Integer.bitCount(i)] += count[i]
            }
            for (i in 1..5) {
                out.print(res[i].toString() + " ")
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

        fun nextInt(): Int {
            return next().toInt()
        }

        init {
            reader = BufferedReader(InputStreamReader(stream), 32768)
            tokenizer = null
        }
    }
}