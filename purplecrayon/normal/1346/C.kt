import kotlin.Throws
import java.io.IOException
import kotlin.jvm.JvmStatic
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.StringTokenizer
import java.util.Arrays

    fun main(args: Array<String>) {
        val br = BufferedReader(InputStreamReader(System.`in`))
        val pw = PrintWriter(System.out)
        val tests: Int
        tests = br.readLine().toInt()
        for (a in 0 until tests) {
            var n: Int
            var k: Long
            var x: Long
            var y: Long
            var st = StringTokenizer(br.readLine())
            n = st.nextToken().toInt()
            k = st.nextToken().toLong()
            x = st.nextToken().toLong()
            y = st.nextToken().toLong()
            val arr = LongArray(n)
            var sum: Long = 0
            st = StringTokenizer(br.readLine())
            for (i in 0 until n) {
                arr[i] = st.nextToken().toInt().toLong()
                sum += arr[i]
            }
            Arrays.sort(arr)
            var cost: Long = 0
            var use_y = Long.MAX_VALUE
            for (i in n - 1 downTo -1 + 1) {
                if (sum <= n * k && use_y == Long.MAX_VALUE) {
                    use_y = cost + y
                }
                if (arr[i] <= k) break
                cost += x
                sum -= arr[i]
            }
            pw.write(
                """
    ${Math.min(cost, use_y)}
    
    """.trimIndent()
            )
        }
        pw.close()
    }