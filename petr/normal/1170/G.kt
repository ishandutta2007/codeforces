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
    val solver = Main.TaskG()
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
        val solver = TaskG()
        solver.solve(1, `in`, out)
        out.close()
    }

    internal class TaskG {
        fun solve(testNumber: Int, `in`: InputReader, out: PrintWriter) {
            val n = `in`.nextInt()
            val vs = Array<TaskG.Vertex>(n, {_ -> Vertex()});
            for (i in 0 until n) {
                vs[i] = TaskG.Vertex()
            }
            for (i in 0 until n) {
                vs[i].index = i + 1
            }
            val m = `in`.nextInt()
            for (i in 0 until m) {
                val a = vs[`in`.nextInt() - 1]
                val b = vs[`in`.nextInt() - 1]
                if (a === b) {
                    ++a.numLoops
                    continue
                }
                val ab = TaskG.Edge()
                val ba = TaskG.Edge()
                ab.dest = b
                ab.rev = ba
                ba.dest = a
                ba.rev = ab
                a.outgo.add(ab)
                b.outgo.add(ba)
            }
            for (v in vs) {
                if (v.outgo.size % 2 != 0) {
                    out.println("NO")
                    return
                }
                var i = 0
                while (i < v.outgo.size) {
                    val e1 = v.outgo[i]
                    val e2 = v.outgo[i + 1]
                    e1.rev!!.next = e2
                    e2.rev!!.next = e1
                    i += 2
                }
            }
            out.println("YES")
            val cycles = ArrayList<List<TaskG.Vertex>>()
            for (v in vs) {
                val cycle = ArrayList<TaskG.Vertex>()
                cycle.add(v)
                for (i in 0 until v.numLoops) {
                    cycles.add(cycle)
                }
            }
            val stack = ArrayList<TaskG.Edge>()
            for (v in vs) {
                for (start in v.outgo) {
                    if (start.used) continue
                    v.stackPos = 0
                    stack.add(start)
                    while (true) {
                        val last = stack[stack.size - 1]
                        if (last.dest!!.stackPos >= 0) {
                            val cycle = ArrayList<TaskG.Vertex>()
                            val pos = last.dest!!.stackPos
                            for (i in pos until stack.size) {
                                val e = stack[i]
                                cycle.add(e.dest!!)
                                e.dest!!.stackPos = -1
                                e.rev!!.used = true
                                e.used = e.rev!!.used
                            }
                            cycles.add(cycle)
                            while (stack.size > pos) stack.removeAt(stack.size - 1)
                        }
                        if (stack.isEmpty()) break
                        last.dest!!.stackPos = stack.size
                        stack.add(last.next!!)
                    }
                }
            }
            out.println(cycles.size)
            for (cycle in cycles) {
                out.print((cycle.size + 1).toString() + " " + cycle[cycle.size - 1].index)
                for (v in cycle) {
                    out.print(" " + v.index)
                }
                out.println()
            }
        }

        internal class Edge {
            var used = false
            var dest: TaskG.Vertex? = null
            var rev: TaskG.Edge? = null
            var next: TaskG.Edge? = null

        }

        internal class Vertex {
            var numLoops = 0
            var stackPos = -1
            var index: Int = 0
            var outgo: MutableList<TaskG.Edge> = ArrayList()

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