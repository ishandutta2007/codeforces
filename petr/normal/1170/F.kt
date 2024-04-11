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
    val solver = Main.TaskF()
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
        val solver = TaskF()
        solver.solve(1, `in`, out)
        out.close()
    }

    internal class TaskF {
        fun solve(testNumber: Int, `in`: InputReader, out: PrintWriter) {
            val n = `in`.nextInt()
            val m = `in`.nextInt()
            val k = `in`.nextLong()
            val a = LongArray(n)
            for (i in 0 until n) {
                a[i] = `in`.nextLong()
            }
            val random = Random(5413531511L)
            for (i in 0 until n) {
                val j = random.nextInt(i + 1)
                val t = a[i]
                a[i] = a[j]
                a[j] = t
            }
            Arrays.sort(a)

            val prefixSum = LongArray(n + 1)
            for (i in 0 until n) {
                prefixSum[i + 1] = prefixSum[i] + a[i]
            }
            var res = java.lang.Long.MAX_VALUE
            var first = 0
            while (first + m <= n) {
                var midpoint = first + (m - 1) / 2
                var optimal = a[midpoint]
                var totalIncrease = optimal * (midpoint - first) - (prefixSum[midpoint] - prefixSum[first])
                if (totalIncrease <= k) {
                    val totalDecrease = prefixSum[first + m] - prefixSum[midpoint] - optimal * (first + m - midpoint)
                    res = Math.min(res, totalIncrease + totalDecrease)
                } else {
                    var left = first
                    var right = midpoint
                    while (right - left > 1) {
                        midpoint = (left + right) / 2
                        optimal = a[midpoint]
                        totalIncrease = optimal * (midpoint - first) - (prefixSum[midpoint] - prefixSum[first])
                        if (totalIncrease <= k) {
                            left = midpoint
                        } else {
                            right = midpoint
                        }
                    }
                    midpoint = left
                    optimal = a[midpoint]
                    totalIncrease = optimal * (midpoint - first) - (prefixSum[midpoint] - prefixSum[first])
                    val remaining = k - totalIncrease
                    ++midpoint
                    val extra = remaining / (midpoint - first)
                    optimal += extra
                    totalIncrease = optimal * (midpoint - first) - (prefixSum[midpoint] - prefixSum[first])
                    if (totalIncrease > k) throw RuntimeException()
                    val totalDecrease = prefixSum[first + m] - prefixSum[midpoint] - optimal * (first + m - midpoint)
                    res = Math.min(res, totalIncrease + totalDecrease)
                }
                ++first
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

        fun nextLong(): Long {
            return java.lang.Long.parseLong(next())
        }

    }
}