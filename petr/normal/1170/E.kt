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
    val solver = Main.TaskE()
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
        val solver = TaskE()
        solver.solve(1, `in`, out)
        out.close()
    }

    internal class TaskE {
        fun solve(testNumber: Int, `in`: InputReader, out: PrintWriter) {
            val n = `in`.nextInt()
            val total = `in`.nextInt()
            val width = IntArray(n)
            for (i in 0 until n) {
                width[i] = `in`.nextInt()
            }
            val prefixSum = IntArray(n + 1)
            for (i in 0 until n) {
                prefixSum[i + 1] = prefixSum[i] + width[i]
            }
            val q = `in`.nextInt()
            for (qi in 0 until q) {
                val count = `in`.nextInt()
                var atPos = 0
                var atDoor = 0
                for (i in 0..count) {
                    val w: Int
                    if (i == count)
                        w = total
                    else
                        w = `in`.nextInt() - 1
                    var left = 0
                    var right = n - atDoor + 1
                    while (right - left > 1) {
                        val middle = (left + right) / 2
                        if (prefixSum[atDoor + middle] - prefixSum[atDoor] <= w - atPos) {
                            left = middle
                        } else {
                            right = middle
                        }
                    }
                    atDoor += left
                    atPos = w + 1
                }
                if (atDoor == n) {
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