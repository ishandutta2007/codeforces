import java.io.PrintWriter

val pw = PrintWriter(System.out)
fun main(args: Array<String>) {
    var n = nextInt()
    var cs = mutableListOf<Int>()
    var ps = mutableListOf<Int>()
    var usd = mutableListOf<Boolean>()
    repeat(n) {
        var (c, p) = listOfInt()
        cs.add(c)
        ps.add(p)
        usd.add(false)
    }
    var t = nextInt()
    var qs = listOfInt()
    var re = mutableListOf<Pair<Int, Int>>()
    var sum = 0L
    MutableList(t){it}.sortedBy{ i -> qs[i]}.forEach{ i ->
        var x = qs[i]
        var bi = -1
        var b = 0
        repeat(n) { j ->
            if (!usd[j] && cs[j] <= x && ps[j] > b) {
                b = ps[j]
                bi = j
            }
        }
        if (bi < 0) return@forEach
        usd[bi] = true
        re.add(Pair(bi, i))
        sum += b
    }
    print("${re.size} ${sum}\n")
    print(re.map { pr -> "${pr.first + 1} ${pr.second + 1}" }.joinToString("\n"))
    pw.flush()
}

fun next() = readLine()!!
fun nextInt() = next().toInt()
fun nextLong() = next().toLong()
fun nextDouble() = next().toDouble()
fun listOfString() = next().split(" ")
fun listOfInt() = listOfString().map { it.toInt() }
fun listOfLong() = listOfString().map { it.toLong() }
fun listOfDouble() = listOfString().map { it.toDouble() }