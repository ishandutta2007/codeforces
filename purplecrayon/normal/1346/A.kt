import kotlin.Throws
import java.io.IOException
import kotlin.jvm.JvmStatic
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.StringTokenizer

    fun main(args: Array<String>) {
        val br = BufferedReader(InputStreamReader(System.`in`))
        val tests = br.readLine().toInt()
        val pw = PrintWriter(System.out)
        for (a in 0 until tests) {
            val st = StringTokenizer(br.readLine())
            val n = st.nextToken().toInt()
            val k = st.nextToken().toInt()
            val d = n / (k * k * k + k * k + k + 1)
            pw.write(
                """$d ${d * k} ${d * k * k} ${d * k * k * k}
"""
            )
        }
        pw.close()
    }