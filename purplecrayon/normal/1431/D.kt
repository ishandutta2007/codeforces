import kotlin.Throws
import java.io.IOException
import kotlin.jvm.JvmStatic
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.StringTokenizer
import java.util.Arrays
import java.util.Comparator

internal class Sorter : Comparator<Array<Int?>> {
    override fun compare(a: Array<Int?>, b: Array<Int?>): Int {
        return Integer.compare(a[0]!!, b[0]!!)
    }
}

    fun main(args: Array<String>) {
        val br = BufferedReader(InputStreamReader(System.`in`))
        val pw = PrintWriter(System.out)
        val tests = br.readLine().toInt()
        for (z in 0 until tests) {
            val len = br.readLine().toInt()
            val array = Array(len) { arrayOfNulls<Int>(2) }
            val st = StringTokenizer(br.readLine())
            for (i in 0 until len) {
                array[i][0] = st.nextToken().toInt()
                array[i][1] = i
            }
            Arrays.sort(array, Sorter())
            var used = 0
            var low = 0
            var high = len - 1
            val ans = IntArray(len)
            for (i in 0 until len) {
                if (used < array[low][0]!!) {
                    ans[i] = array[high][1]!! + 1
                    high--
                } else {
                    ans[i] = array[low][1]!! + 1
                    low++
                    used = 0
                }
                used++
            }
            for (i in 0 until len) {
                pw.print(ans[i].toString() + if (i == len - 1) "\n" else " ")
            }
        }
        pw.close()
    }