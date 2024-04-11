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
        val solver = JPeshki()
        solver.solve(1, `in`, out)
        out.close()
    }

    internal class JPeshki {
        fun solve(testNumber: Int, `in`: InputReader, out: PrintWriter) {
            val n = `in`.nextInt()
            val pawns = arrayOfNulls<Pawn>(n)
            for (i in 0 until n) {
                pawns[i] = Pawn()
                pawns[i]!!.x = `in`.nextInt()
                pawns[i]!!.y = `in`.nextInt()
            }
            Arrays.sort(pawns) { o1, o2 ->
                var z = Integer.compare(o1!!.y, o2!!.y)
                if (z == 0) {
                    z = Integer.compare(o1.x, o2.x)
                }
                z
            }
            var res = n
            for (parity in 0..1) {
                var nthis = 0
                var nthat = 0
                val id = IntArray(n)
                for (i in 0 until n) if (pawns[i]!!.y % 2 == parity) {
                    id[i] = nthis++
                } else {
                    id[i] = nthat++
                }
                val done = BooleanArray(n)
                var i = 0
                while (i < n) {
                    var j = i
                    while (j < n && pawns[j]!!.y == pawns[i]!!.y) ++j
                    if (pawns[i]!!.y % 2 == parity) {
                        var pi = i
                        while (pi > 0 && pawns[pi - 1]!!.y == pawns[i]!!.y - 1) --pi
                        var nj = j
                        while (nj < n && pawns[nj]!!.y == pawns[i]!!.y + 1) ++nj
                        var ptr = j - 1
                        for (o in i - 1 downTo pi) if (!done[o]) {
                            while (ptr >= i && (done[ptr] || pawns[ptr]!!.x >= pawns[o]!!.x)) --ptr
                            if (ptr >= i) {
                                --res
                                done[o] = true
                                done[ptr] = true
                            }
                        }
                        ptr = j
                        for (u in i until j) if (!done[u]) {
                            while (ptr < nj && (done[ptr] || pawns[ptr]!!.x <= pawns[u]!!.x)) ++ptr
                            if (ptr < nj) {
                                --res
                                done[u] = true
                                done[ptr] = true
                            }
                        }
                    }
                    i = j
                }
            }
            out.println(res)
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

    internal class Pawn {
        var x = 0
        var y = 0
    }
}