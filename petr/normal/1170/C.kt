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
    val solver = Main.TaskC()
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
        val solver = TaskC()
        solver.solve(1, `in`, out)
        out.close()
    }

    internal class TaskC {
        fun solve(testNumber: Int, `in`: InputReader, out: PrintWriter) {
            val nt = `in`.nextInt()
            for (it in 0 until nt) {
                val s = `in`.next()
                val t = `in`.next()
                var p1 = 0
                var p2 = 0
                var ok = true
                while (p1 < s.length && p2 < t.length) {
                    val c1 = s[p1]
                    val c2 = t[p2]
                    if (c1 == c2) {
                        ++p1
                        ++p2
                    } else if (c1 == '-' && c2 == '+' && p1 + 1 < s.length && s[p1 + 1] == '-') {
                        p1 += 2
                        ++p2
                    } else {
                        ok = false
                        break
                    }
                }
                if (ok && p1 == s.length && p2 == t.length) {
                    out.println("YES")
                } else {
                    out.println("NO")
                }
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