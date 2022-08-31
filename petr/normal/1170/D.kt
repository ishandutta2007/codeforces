import java.io.IOException
import java.io.InputStream
import java.io.PrintWriter
import java.util.Arrays
import java.util.StringTokenizer
import java.io.BufferedReader
import java.io.InputStreamReader

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
fun main() {
    val inputStream = System.`in`
    val outputStream = System.out
    val `in` = Main.InputReader(inputStream)
    val out = PrintWriter(outputStream)
    val solver = Main.TaskD()
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
        val solver = TaskD()
        solver.solve(1, `in`, out)
        out.close()
    }

    internal class TaskD {
        fun solve(testNumber: Int, `in`: InputReader, out: PrintWriter) {
            val m = `in`.nextInt()
            val b = IntArray(m)
            for (i in 0 until m) b[i] = `in`.nextInt()
            var n = 0
            for (x in b) if (x == -1) ++n
            val next = IntArray(m)
            val last = IntArray(n)
            val count = IntArray(n)
            val nextAvailable = IntArray(n)
            val prevAvailable = IntArray(n)
            for (i in 0 until n) {
                prevAvailable[i] = (i + n - 1) % n
                nextAvailable[i] = (i + 1) % n
            }
            Arrays.fill(last, -1)
            Arrays.fill(next, -1)
            var at = 0
            for (i in 0 until m) {
                val cur = b[i]
                ++count[at]
                if (last[at] >= 0) {
                    next[last[at]] = i
                }
                last[at] = i
                if (cur < 0) {
                    val pr = prevAvailable[at]
                    if (pr == at) {
                        if (i != m - 1) throw RuntimeException()
                        break
                    }
                    val nx = nextAvailable[at]
                    nextAvailable[pr] = nx
                    prevAvailable[nx] = pr
                }
                at = nextAvailable[at]
            }
            out.println(n)
            for (i in 0 until n) {
                out.print(count[i] - 1)
                at = i
                while (b[at] >= 0) {
                    out.print(" " + b[at])
                    at = next[at]
                }
                out.println()
            }
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