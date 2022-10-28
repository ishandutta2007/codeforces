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
        val tests = br.readLine().toInt()
        for (i in 0 until tests) {
            val len = br.readLine().toInt()
            val array = LongArray(len)
            val st = StringTokenizer(br.readLine())
            for (j in 0 until len) {
                val a = st.nextToken().toLong()
                array[j] = a
            }
            Arrays.sort(array)
            var max: Long = 0
            for (j in 0 until len) {
                var price = array[j]
                price *= (len - j).toLong()
                //System.out.println(price);
                max = Math.max(price, max)
            }
            pw.write(
                """
    ${java.lang.Long.toString(max)}
    
    """.trimIndent()
            )
        }
        pw.close()
    }