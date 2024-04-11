import java.lang.AssertionError
import java.lang.StringBuilder
import java.util.*

val readQueue = ArrayDeque<String>()
fun getInput(): String {
    if (readQueue.isEmpty()) readLine()!!.split(' ', '\n').let{ readQueue.addAll(it) }
    return readQueue.pop()
}

fun getInt() = getInput().toInt()
fun getLong() = getInput().toLong()
fun getString() = getInput()

const val MOD107 = 1000000007L
const val MOD998 = 998244353L
fun myAssert(b : Boolean) {
    if (!b) throw AssertionError()
}

fun main() {
    val dr = arrayOf(1, -1, 0, 0)
    val dc = arrayOf(0, 0, 1, -1)

    var t = getInt()
    while (t-- > 0) {
        var (n, m) = Array(2) { getInt() }
        var a = Array(n) { Array(m) { getInt() } }

        var biomes = 0
        for (i in a)
            for (j in i)
                if (j != 0)
                    biomes++

        var seq = mutableListOf<Int>()
        var trav = Array(n) { Array(m) { false } }
        var done = false
        var can = true

        fun dfs(u : Pair<Int, Int>) {
            trav[u.first][u.second] = true
            seq.add(a[u.first][u.second])

            for (dir in 0 until 4) {
                var r = u.first + dr[dir]
                var c = u.second + dc[dir]

                if (r in 0 until n && c in 0 until m && a[r][c] != 0 && !trav[r][c]) {
                    dfs(Pair(r, c))
                    seq.add(a[u.first][u.second])
                }
            }
        }

        for (i in 0 until n) {
            for (j in 0 until m) {
                if (a[i][j] != 0) {
                    if (done) {
                        if (!trav[i][j])
                            can = false
                    }
                    else {
                        done = true
                        dfs(Pair(i, j))
                    }
                }
            }
        }

        if (can) {
            myAssert(seq.size == biomes * 2 - 1)
            var ans = Array(biomes) { Array(biomes) { 0 } }
            for (i in 0 until biomes)
                for (j in 0 until biomes)
                    ans[i][j] = seq[i + j]

            println("$biomes $biomes")
            println(ans.map { it -> it.joinToString(" ") }.joinToString("\n"))
        }
        else {
            println(-1)
        }
    }
}