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
    val solver = Main.TaskB()
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
        val solver = TaskB()
        solver.solve(1, `in`, out)
        out.close()
    }

    internal class TaskB {
        fun solve(testNumber: Int, `in`: InputReader, out: PrintWriter) {
            val n = `in`.nextInt()
            var max = 0
            var max2 = 0
            var res = 0
            for (i in 0 until n) {
                val a = `in`.nextInt()
                if (max2 > a) {
                    ++res
                }
                if (a > max) {
                    max2 = max
                    max = a
                } else if (a > max2) {
                    max2 = a
                }
            }
            out.println(res)
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