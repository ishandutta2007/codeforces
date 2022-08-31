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
    val solver = Main.TaskA()
    solver.solve(1, `in`, out)
    out.close()
}

object Main {

    internal class TaskA {
        fun solve(testNumber: Int, `in`: InputReader, out: PrintWriter) {
            val nq = `in`.nextInt()
            for (iq in 0 until nq) {
                val x = `in`.nextLong()
                val y = `in`.nextLong()
                val a = Math.min(x - 1, y - 1)
                val b = x - a
                val c = y - a
                out.println("$a $b $c")
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

        fun nextLong(): Long {
            return java.lang.Long.parseLong(next())
        }

    }
}