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
    val solver = Main.TaskI()
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
        val solver = TaskI()
        solver.solve(1, `in`, out)
        out.close()
    }

    internal class TaskI {
        var extraMul: IntArray = IntArray(4 * 200000 + 5)
        var sum: IntArray = IntArray(4 * 200000 + 5)

        fun solve(testNumber: Int, `in`: InputReader, out: PrintWriter) {
            val n = `in`.nextInt()
            val segments = arrayOfNulls<TaskI.Segment>(n)
            for (i in 0 until n) {
                segments[i] = TaskI.Segment()
                segments[i]!!.l = `in`.nextInt()
                segments[i]!!.r = `in`.nextInt()
            }
            Arrays.sort<Segment>(segments) { o1, o2 -> o1.l - o2.l }
            var res: Long = 1
            var i = 0
            while (i < n) {
                var j = i + 1
                var maxR = segments[i]!!.r
                while (j < segments.size && segments[j]!!.l <= maxR) {
                    maxR = Math.max(maxR, segments[j]!!.r)
                    ++j
                }
                res = res * solveRange(segments, i, j, segments[i]!!.l) % MODULO
                i = j
            }
            out.println(res)
        }

        fun initTree(root: Int, rl: Int, rr: Int) {
            extraMul[root] = 1
            sum[root] = 0
            if (rl == rr) return
            val rm = rl + rr shr 1
            initTree(root * 2 + 1, rl, rm)
            initTree(root * 2 + 2, rm + 1, rr)
        }

        fun addToTree(root: Int, rl: Int, rr: Int, at: Int, by: Int) {
            propagate(root, rl, rr)
            if (rl != rr) {
                val rm = rl + rr shr 1
                if (at <= rm) {
                    addToTree(root * 2 + 1, rl, rm, at, by)
                } else {
                    addToTree(root * 2 + 2, rm + 1, rr, at, by)
                }
            }
            sum[root] = (sum[root] + by) % MODULO
            if (rl != rr && sum[root] != ((sum[root * 2 + 1] * extraMul[root * 2 + 1].toLong() + sum[root * 2 + 2] * extraMul[root * 2 + 2].toLong()) % MODULO).toInt()) {
                throw RuntimeException()
            }
        }

        private fun mulBy2(root: Int, rl: Int, rr: Int, left: Int, right: Int) {
            if (left > right) return
            if (rl == left && rr == right) {
                extraMul[root] = extraMul[root] * 2 % MODULO
                return
            }
            propagate(root, rl, rr)
            val rm = rl + rr shr 1
            mulBy2(root * 2 + 1, rl, rm, left, Math.min(rm, right))
            mulBy2(root * 2 + 2, rm + 1, rr, Math.max(left, rm + 1), right)
            sum[root] = ((sum[root * 2 + 1] * extraMul[root * 2 + 1].toLong() + sum[root * 2 + 2] * extraMul[root * 2 + 2].toLong()) % MODULO).toInt()
        }

        private fun propagate(root: Int, rl: Int, rr: Int) {
            if (extraMul[root] != 1) {
                val mul = extraMul[root].toLong()
                extraMul[root] = 1
                sum[root] = (sum[root] * mul % MODULO).toInt()
                if (rl != rr) {
                    extraMul[root * 2 + 1] = (extraMul[root * 2 + 1] * mul % MODULO).toInt()
                    extraMul[root * 2 + 2] = (extraMul[root * 2 + 2] * mul % MODULO).toInt()
                }
            }
        }

        private fun getSum(root: Int, rl: Int, rr: Int, left: Int, right: Int): Long {
            if (left > right) return 0
            if (rl == left && rr == right) return sum[root] * extraMul[root].toLong() % MODULO
            val rm = rl + rr shr 1
            var res = getSum(root * 2 + 1, rl, rm, left, Math.min(rm, right))
            res += getSum(root * 2 + 2, rm + 1, rr, Math.max(left, rm + 1), right)
            return res * extraMul[root] % MODULO
        }

        private fun solveRange(segments: Array<Segment?>, first: Int, last: Int, start: Int): Long {
            Arrays.sort(segments, first, last) { o1, o2 -> o1!!.r - o2!!.r }
            val treeSize = last - first + 1
            initTree(0, 0, treeSize - 1)
            addToTree(0, 0, treeSize - 1, 0, 1)
            for (i in first until last) {
                var left = first - 2
                var right = last
                while (right - left > 1) {
                    val middle = (left + right) / 2
                    val pos = if (middle < first) start else segments[middle]!!.r
                    if (pos >= segments[i]!!.l) {
                        right = middle
                    } else {
                        left = middle
                    }
                }
                val take = right - first + 1
                val ways = getSum(0, 0, treeSize - 1, take, treeSize - 1)
                left = i
                right = last
                while (right - left > 1) {
                    val middle = (left + right) / 2
                    if (segments[middle]!!.r <= segments[i]!!.r) {
                        left = middle
                    } else {
                        right = middle
                    }
                }
                addToTree(0, 0, treeSize - 1, left - first + 1, ways.toInt())
                mulBy2(0, 0, treeSize - 1, 0, take - 1)
            }
            return getSum(0, 0, treeSize - 1, treeSize - 1, treeSize - 1)
        }

        internal class Segment {
            var l: Int = 0
            var r: Int = 0

        }

        companion object {
            val MODULO = 998244353
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