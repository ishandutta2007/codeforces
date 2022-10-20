import java.util.*
import kotlin.collections.ArrayList

fun get(u : Char) : Int {
    if (u == 'k') return 0
    if (u == 'o') return 1
    if (u == 't') return 2
    if (u == 'l') return 3
    if (u == 'i') return 4
    if (u == 'n') return 5
    return 6
}

fun main() {
    val sc = Scanner(System.`in`);
    var n = sc.nextInt()
    var a = Array(6) { ArrayList<Pair<Int, Int>>() }
    for (i in 0 until n) {
        var u = sc.next()
        var start = get(u[0])
        var finish = (get(u.last()) + 1) % 6
        a[start].add(Pair(finish, i))
    }
    var st = ArrayList<Pair<Int, Int>>()
    st.add(Pair(0, -1))
    var res = ArrayList<Int>()
    while (st.isNotEmpty()) {
        var foo = st.last()
        var u = foo.first
        var id = foo.second
        if (a[u].isNotEmpty()) {
            var now = a[u].last()
            a[u].removeAt(a[u].lastIndex)
            st.add(now)
        } else {
            st.removeAt(st.lastIndex)
            res.add(id)
        }
    }
    for (i in res.size - 2 downTo 0) {
        print("${res[i] + 1} ")
    }
}