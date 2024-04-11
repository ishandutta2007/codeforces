import java.io.OutputStream
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
    val solver = Main.TaskD()
    solver.solve(`in`, out)
    out.close()
}


object Main {
    internal class TaskD {
        var WILDCARD = 26
        var numInvalid: Int = 0
        var leafDepth: Int = 0

        fun solve(`in`: InputReader, out: PrintWriter) {
            val n = `in`.nextInt()
            val q = `in`.nextInt()
            val vs = Array<TaskD.Vertex>(n, {_ -> TaskD.Vertex()})
            vs[0].parentChar = -1
            for (i in 1 until n) {
                vs[i] = TaskD.Vertex()
                vs[i].parent = vs[`in`.nextInt() - 1]
                ++vs[i].parent!!.numChildren
                vs[i].depth = 1 + vs[i].parent!!.depth
                val ch = `in`.next()[0]
                if (ch == '?') {
                    vs[i].parentChar = WILDCARD
                } else {
                    vs[i].parentChar = ch - 'a'
                }
            }
            leafDepth = -1
            for (v in vs)
                if (v.numChildren == 0) {
                    if (leafDepth < 0) leafDepth = v.depth
                    if (leafDepth != v.depth) {
                        for (i in 0 until q) {
                            out.println("Fou")
                        }
                        return
                    }
                }
            if (leafDepth < 0) throw RuntimeException()
            var interesting = arrayOfNulls<TaskD.Vertex>(n)
            var interestingCount = 0
            for (v in vs) {
                if (v.parent == null || v.numChildren != 1) {
                    interesting[interestingCount++] = v
                }
            }
            interesting = Arrays.copyOf<Vertex>(interesting, interestingCount)
            reverseArray(interesting)
            for (v in interesting) {
                v!!.quickCount = IntArray(27)
                v.subtreeCount = IntArray(27)
            }
            numInvalid = 0
            for (v in interesting) {
                v!!.subtreeSum = 0
                for (i in 0..25) v.subtreeSum += v.subtreeCount!![i]
                if (v.subtreeSum > leafDepth - v.depth) {
                    ++numInvalid
                }
                if (v.parent != null) {
                    v.quickChild = v
                    ++v.quickCount!![v.parentChar]
                    var u = v.parent
                    while (u!!.parent != null && u.numChildren == 1) {
                        ++v.quickCount!![u.parentChar]
                        u.quickChild = v
                        u = u.parent
                    }
                    v.quickParent = u
                    for (i in 0..25) {
                        u.subtreeCount!![i] = Math.max(u.subtreeCount!![i], v.subtreeCount!![i] + v.quickCount!![i])
                    }
                    v.nextSibling = u.firstChild
                    u.firstChild = v
                }
            }
            for (qi in 0 until q) {
                val u = vs[`in`.nextInt() - 1]
                val v = u.quickChild
                val c1 = u.parentChar
                val ch = `in`.next()[0]
                val c2: Int
                if (ch == '?') {
                    c2 = WILDCARD
                } else {
                    c2 = ch - 'a'
                }
                if (c1 != c2) {
                    u.parentChar = c2
                    if (c1 < 26) {
                        --v!!.quickCount!![c1]
                        propagate(v, c1)
                    }
                    if (c2 < 26) {
                        ++v!!.quickCount!![c2]
                        propagate(v, c2)
                    }
                }
                if (numInvalid == 0) {
                    var s = 0
                    val spare = leafDepth - vs[0].subtreeSum
                    for (i in 0..25) {
                        s += (i + 1) * (vs[0].subtreeCount!![i] + spare)
                    }
                    out.println("Shi $s")
                } else {
                    out.println("Fou")
                }
            }
        }

        private fun propagate(v: TaskD.Vertex, what: Int) {
            val u = v.quickParent
            if (u!!.subtreeSum > leafDepth - u.depth) {
                --numInvalid
            }
            val old = u.subtreeCount!![what]
            u.subtreeSum -= old
            u.subtreeCount!![what] = 0
            var t = u.firstChild
            while (t != null) {
                u.subtreeCount!![what] = Math.max(u.subtreeCount!![what], t.subtreeCount!![what] + t.quickCount!![what])
                t = t.nextSibling
            }
            u.subtreeSum += u.subtreeCount!![what]
            if (u.subtreeSum > leafDepth - u.depth) {
                ++numInvalid
            }
            if (u.parent != null && u.subtreeCount!![what] != old) {
                propagate(u, what)
            }
        }

        private fun reverseArray(a: Array<TaskD.Vertex>) {
            var i = 0
            var j = a.size - 1
            while (i < j) {
                val t = a[i]
                a[i] = a[j]
                a[j] = t
                ++i
                --j
            }
        }

        internal class Vertex {
            var parent: TaskD.Vertex? = null
            var parentChar: Int = 0
            var depth: Int = 0
            var numChildren: Int = 0
            var quickParent: TaskD.Vertex? = null
            var quickChild: TaskD.Vertex? = null
            var quickCount: IntArray? = null
            var subtreeCount: IntArray? = null
            var firstChild: TaskD.Vertex? = null
            var nextSibling: TaskD.Vertex? = null
            var subtreeSum: Int = 0

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