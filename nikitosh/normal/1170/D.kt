import java.io.*
import java.util.*

fun main() {
    val bi = BufferedReader(InputStreamReader(System.`in`));
    val n = Integer.parseInt(bi.readLine())
    val line = bi.readLine()
    val a = IntArray(n, {it -> 0})
    var it = 0
    for (numStr in line.split(" ")) {
        a[it] = Integer.parseInt(numStr)
        it += 1
    }
    var cnt = 0
    for (i in 1..n) {
        if (a[i - 1] == -1)
            cnt += 1
    }
    var list = arrayListOf<ArrayList<Int>>()
    for (i in 1..cnt)
        list.add(arrayListOf())
    var cur = 0
    val next = IntArray(cnt, {it -> it + 1})
    val was = IntArray(cnt, {it -> 0})
    next[cnt - 1] = 0
    for (i in 1..n) {
        if (a[i - 1] == -1) {
            was[cur] = 1
        } else
            list.get(cur).add(a[i - 1])
        if (i == n)
            break
        val curr = cur
        do {    
            cur = next[cur]
        } while (was[cur] == 1)
        next[curr] = cur
    }
    val log = BufferedWriter(OutputStreamWriter(System.`out`));
    log.write(cnt.toString() + "\n")
    for (i in 0..(cnt - 1)) {
        val lst = list.get(i)
        log.write(lst.size.toString() + " ")
        for (i in lst) {
            log.write(i.toString() + " ")
        }
        log.write("\n")
    }
    log.flush();
}