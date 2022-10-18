private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun rec(i: Int, adj: Array<ArrayList<Int>>, pos: Array<Int>, path: ArrayList<Int>) {
    while (pos[i] < adj[i].size) {
        val j = adj[i][ pos[i] ]
        pos[i]++
        rec(j, adj, pos, path)
    }
    path.add(i)
}

fun main() {
    val n = readInt()
    val src = Array<Int>(n) { 0 }
    val dst = Array<Int>(n) { 0 }
    val adj = Array<ArrayList<Int>>(6) { ArrayList<Int>() }
    val indices = Array<Array<ArrayList<Int>>>(6) { Array<ArrayList<Int>>(6) { ArrayList<Int>() } }

    for (i in 0 until n) {
        val str = readLn()
        if (str[0] == 'k') src[i] = 0
        if (str[0] == 'o') src[i] = 1
        if (str[0] == 't') src[i] = 2
        if (str[0] == 'l') src[i] = 3
        if (str[0] == 'i') src[i] = 4
        if (str[0] == 'n') src[i] = 5
        dst[i] = (src[i] + str.length) % 6
        indices[ src[i] ][ dst[i] ].add(i+1)
        adj[ src[i] ].add(dst[i])
    }

    val pos = Array<Int>(6) { 0 }
    val path = ArrayList<Int>()
    rec(0, adj, pos, path)
    path.reverse()

    val ipos = Array<Array<Int>>(6) { Array<Int>(6) { 0 } }
    val res = ArrayList<Int>()
    for (i in 0 until path.size-1) {
        val a = path[i]
        val b = path[i+1]
        res.add(indices[a][b][ ipos[a][b]++ ])
    }
    println(res.joinToString(" "))
}