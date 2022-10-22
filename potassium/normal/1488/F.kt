import java.lang.AssertionError
import java.math.BigInteger
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


class SegTree(n : Int) {
    class Node() {
        var sum = 0L
        var lazy = 0L
    }

    var tree = Array(n * 4 + 7) { Node() }

    fun pushdown(id : Int, l : Int, r : Int) {
        if (tree[id].lazy == 0L || l == r)
            return;

        var mid = (l + r) / 2
        var lc = id * 2
        var rc = lc + 1
        tree[lc].sum += tree[id].lazy * (mid - l + 1)
        tree[lc].lazy += tree[id].lazy
        tree[rc].sum += tree[id].lazy * (r - mid)
        tree[rc].lazy += tree[id].lazy
        tree[id].lazy = 0
    }

    fun upd(id : Int, l : Int, r : Int, ql : Int, qr : Int, x : Long) {
        if (qr < l || r < ql) return
        pushdown(id, l, r)
        if (ql <= l && r <= qr) {
            tree[id].sum += x * (r - l + 1)
            tree[id].lazy += x
            return
        }

        var mid = (l + r) / 2
        if (ql <= mid) upd(id * 2, l, mid, ql, qr, x)
        if (mid < qr) upd(id * 2 + 1, mid + 1, r, ql, qr, x)
        tree[id].sum = tree[id * 2].sum + tree[id * 2 + 1].sum
    }

    fun qry(id : Int, l : Int, r : Int, ql : Int, qr : Int) : Long {
        if (qr < l || r < ql) return 0
        pushdown(id, l, r)
        if (ql <= l && r <= qr)
            return tree[id].sum

        var mid = (l + r) / 2
        if (qr <= mid) return qry(id * 2, l, mid, ql, qr)
        if (mid < ql) return qry(id * 2 + 1, mid + 1, r, ql, qr)
        return qry(id * 2, l, mid, ql, qr) + qry(id * 2 + 1, mid+1, r, ql, qr)
    }
}

fun main() {
    var n = getInt()
    var c = MutableList(n + 1) { 0 }
    for (i in 1 .. n)
        c[i] = getInt()

    var q = getInt()
    var qry = MutableList(q) { Pair(Pair(getInt(), getInt()), it) }
    qry.sortByDescending { it.first.second }

    var ans = MutableList(q) { 0L }

    var st = SegTree(n + 7)
    var stk = mutableListOf<Pair<Int, Int>>()
    stk.add(Pair(Int.MAX_VALUE, 0))
    for (i in 1 .. n) {
        while (!stk.isEmpty() && stk.last().first <= c[i]) {
            var x = stk.last().first
            var idx = stk.last().second
            stk.removeLast()

            st.upd(1, 1, n, stk.last().second + 1, idx, -x.toLong())
        }

        st.upd(1, 1, n, stk.last().second + 1, i, c[i].toLong())
        stk.add(Pair(c[i], i))

        while (!qry.isEmpty() && qry.last().first.second == i) {
            var l = qry.last().first.first
            var r = qry.last().first.second
            var idx = qry.last().second
            qry.removeLast()

            ans[idx] = st.qry(1, 1, n, l, r)
        }
    }

    println(ans.joinToString(" "))
}