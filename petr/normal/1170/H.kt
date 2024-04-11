import java.io.IOException
import java.io.InputStream
import java.io.PrintWriter
import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
fun main() {
    val inputStream = System.`in`
    val outputStream = System.out
    val `in` = Main.InputReader(inputStream)
    val out = PrintWriter(outputStream)
    val solver = Main.TaskH()
    solver.solve(1, `in`, out)
    out.close()
}

object Main {
    @JvmStatic
    fun main(args: Array<String>) {
        val inputStream = System.`in`
        val outputStream = System.out
        val `in` = InputReader(inputStream)
        val out = PrintWriter(outputStream)
        val solver = TaskH()
        solver.solve(1, `in`, out)
        out.close()
    }

    internal class TaskH {
        fun solve(testNumber: Int, `in`: InputReader, out: PrintWriter) {
            val numTests = `in`.nextInt()
            val random = Random(5413531511L)
            for (it in 0 until numTests) {
                val n = `in`.nextInt()
                val a = IntArray(n)
                for (i in 0 until n) {
                    a[i] = `in`.nextInt()
                }
                for (i in 0 until n) {
                    val j = random.nextInt(i + 1)
                    val t = a[i]
                    a[i] = a[j]
                    a[j] = t
                }
                Arrays.sort(a)
                solveOne(a, out)
            }
        }

        private fun solveOne(a: IntArray, out: PrintWriter) {
            var a = a
            var n = a.size
            var i = 0
            while (i < a.size) {
                var j = i
                while (j < a.size && a[i] == a[j]) ++j
                val count = j - i
                val remains = n - count
                if (count >= remains) {
                    if (count > remains && (i == 0 || j == a.size)) {
                        out.println(remains * 2 + 1)
                        out.print(a[i])
                        for (k in a.indices) {
                            if (k < i || k >= j) {
                                out.print(" " + a[k])
                                out.print(" " + a[i])
                            }
                        }
                        out.println()
                        return
                    }
                    val b = IntArray(2 * remains)
                    var togo = remains
                    var ptr = 0
                    for (k in a.indices) {
                        if (k < i || k >= j) {
                            b[ptr++] = a[k]
                        } else {
                            if (togo > 0) {
                                --togo
                                b[ptr++] = a[k]
                            }
                        }
                    }
                    if (ptr != b.size) throw RuntimeException()
                    a = b
                    n = a.size
                    break
                }
                i = j
            }
            out.println(a.size)
            var half = (a.size + 1) / 2 - 1
            val by = a.size / 2
            var pos = 0
            while (pos < a.size) {
                out.print(a[half].toString() + " ")
                ++pos
                if (pos >= a.size) break
                out.print(a[half + by].toString() + " ")
                ++pos
                --half
            }
            out.println()
        }

    }

    internal class InputReader(stream: InputStream) {
        var reader: BufferedReader
        var tokenizer: StringTokenizer? = null

        init {
            reader = BufferedReader(InputStreamReader(stream), 32768)
            tokenizer = null
        }

        operator fun next(): String {
            while (tokenizer == null || !tokenizer!!.hasMoreTokens()) {
                try {
                    tokenizer = StringTokenizer(reader.readLine())
                } catch (e: IOException) {
                    throw RuntimeException(e)
                }

            }
            return tokenizer!!.nextToken()
        }

        fun nextInt(): Int {
            return Integer.parseInt(next())
        }

    }
}