import kotlin.math.min
import kotlin.math.max
import java.io.*
import java.util.*

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles
 
var a = ArrayList<List<Int>>()
var used = ArrayList<MutableList<Int>>()
 
fun dfs(i: Int, j: Int): ArrayList<MutableList<Int>> {
    used[i].set(j, 1)
    var children = ArrayList<ArrayList<MutableList<Int>>>()
    var res = ArrayList<MutableList<Int>>()
    
    if (i > 0 && used[i - 1][j] == 0 && a[i - 1][j] != 0) {
        children.add(dfs(i - 1, j))
    }
    if (i + 1 < a.size && used[i + 1][j] == 0 && a[i + 1][j] != 0) {
        children.add(dfs(i + 1, j))
    }
    if (j > 0 && used[i][j - 1] == 0 && a[i][j - 1] != 0) {
        children.add(dfs(i, j - 1))
    }
    if (j + 1 < a[0].size && used[i][j + 1] == 0 && a[i][j + 1] != 0) {
        children.add(dfs(i, j + 1))
    }
    var len = 1
    for (child in children)
        len += child.size
        
    for (i in 0 until len) {
        var tmp = ArrayList<Int>()
        for (j in 0 until len)
            tmp.add(0)
        res.add(tmp)
    }
    
    var cur = 0
    for (child in children) {
        var l = child.size
        res[cur].set(cur, a[i][j])
        for (x in 0 until l)
            for (y in 0 until l)
                res[cur + x].set(cur + 1 + y, child[x][y])
        cur += l
        if (cur + 1 < len)
            res[cur - 1].set(cur + 1, a[i][j])
    }
    res[len - 1].set(len - 1, a[i][j])

    for (diff in 1 until len) {
        for (i in 0 until len) {
            var j = i + diff
            if (j >= len)
                break
            if (res[i][j] == 0)
                res[i].set(j, res[i + 1][j - 1])
        }
    }

    for (diff in 1 until len) {
        for (j in 0 until len) {
            var i = j + diff
            if (i >= len)
                break
            if (res[i][j] == 0)
                res[i].set(j, res[i - 1][j + 1])
        }
    }

    return res
}
 
fun main(args: Array<String>) {
    var t = readInt()
    for (tt in 0 until t) {
        var (n, m) = readInts()
        var cnt = 0
        a = ArrayList<List<Int>>()
        for (i in 0 until n) {
            a.add(readInts())
            for (j in 0 until m)
                if (a[i][j] != 0)
                    cnt += 1
        }
        used = ArrayList<MutableList<Int>>()
        for (i in 0 until n) {
            var tmp = ArrayList<Int>()
            for (j in 0 until m)
                tmp.add(0)
            used.add(tmp)
        }
        
        var was = 0
        var res = ArrayList<MutableList<Int>>()
        for (i in 0 until n) {
            for (j in 0 until m)
                if (a[i][j] != 0) {
                    res = dfs(i, j)
                    was = 1
                    break  
                }
            if (was == 1)
                break
        }
        var k = res.size
        if (k != cnt)
            println(-1)
        else {
            print(k)
            print(" ")
            println(k)
            for (i in 0 until k) {
                for (j in 0 until k) {
                    print(res[i][j])
                    print(" ")
                }
                println();
            }
        }
    }
}