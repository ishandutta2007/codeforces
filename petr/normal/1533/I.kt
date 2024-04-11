import java.io.*
import java.util.*

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
object program {
    @JvmStatic
    fun main(args: Array<String>) {
        val inputStream = System.`in`
        val outputStream: OutputStream = System.out
        val `in` = InputReader(inputStream)
        val out = PrintWriter(outputStream)
        val solver = IEkskursii()
        solver.solve(1, `in`, out)
        out.close()
    }

    internal class IEkskursii {
        var nv = 0
        var ne = 0
        var mink = 0
        fun solve(testNumber: Int, `in`: InputReader, out: PrintWriter) {
            val n1 = `in`.nextInt()
            val n2 = `in`.nextInt()
            val m = `in`.nextInt()
            val k = IntArray(n1)
            for (i in 0 until n1) k[i] = `in`.nextInt()
            val e = Array(n1) { BooleanArray(n2) }
            for (i in 0 until m) {
                val a1 = `in`.nextInt() - 1
                val a2 = `in`.nextInt() - 1
                e[a1][a2] = true
            }
            val mark = BooleanArray(n1)
            val mark2 = BooleanArray(n2)
            var res = 0
            for (i in 0 until n1) if (!mark[i]) {
                mink = k[i]
                nv = 0
                ne = 0
                dfs1(i, e, k, mark, mark2)
                ne /= 2
                if (nv > ne) res += mink
            }
            out.println(res)
        }

        private fun dfs1(i: Int, e: Array<BooleanArray>, k: IntArray, mark: BooleanArray, mark2: BooleanArray) {
            if (mark[i]) return
            ++nv
            mark[i] = true
            mink = Math.min(mink, k[i])
            for (j in 0 until e[i].size) if (e[i][j]) {
                ++ne
                dfs2(j, e, k, mark, mark2)
            }
        }

        private fun dfs2(j: Int, e: Array<BooleanArray>, k: IntArray, mark: BooleanArray, mark2: BooleanArray) {
            if (mark2[j]) return
            ++nv
            mark2[j] = true
            for (i in e.indices) if (e[i][j]) {
                ++ne
                dfs1(i, e, k, mark, mark2)
            }
        }
    }

    internal class InputReader(stream: InputStream?) {
        var reader: BufferedReader
        var tokenizer: StringTokenizer?
        operator fun next(): String {
            while (tokenizer == null || !tokenizer!!.hasMoreTokens()) {
                tokenizer = try {
                    StringTokenizer(reader.readLine())
                } catch (e: IOException) {
                    throw RuntimeException(e)
                }
            }
            return tokenizer!!.nextToken()
        }

        fun nextInt(): Int {
            return next().toInt()
        }

        init {
            reader = BufferedReader(InputStreamReader(stream), 32768)
            tokenizer = null
        }
    }
}