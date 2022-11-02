import java.util.*
import java.io.*;
import kotlin.*
import java.io.InputStream
import java.lang.NumberFormatException
import java.lang.StringBuilder
import kotlin.system.exitProcess as exit
import kotlin.math.min as min
import kotlin.math.max as max
import kotlin.math.abs as abs

val sc = FastScanner();
val pr = PrintWriter(System.out);

// var leaf = ArrayList<Boolean>();
// var poss = ArrayList<Int>();
// var used = ArrayList<Boolean>();

// var G = ArrayList<ArrayList<Int>>();

// fun solve() : Int {
//     leaf.clear();
//     poss.clear();
//     used.clear();
//     G = ArrayList<ArrayList<Int>>();
//     var n = sc.nextInt();
//     var k = sc.nextInt();
//     for (i in 0..n - 1) {
//         G.add(ArrayList<Int>());
//         leaf.add(false);
//         used.add(false);
//     }
//     for (i in 1..n - 1) {
//         var a = sc.nextInt();
//         var b = sc.nextInt();
//         --a;
//         --b;
//         G[a].add(b);
//         G[b].add(a);
//     }
//     var cnt = ArrayList<Int>();
//     for (i in 0..n - 1) cnt.add(0);
//     var cleaf = 1;
//     var ptr = 0;
//     used[0] = true;
//     leaf[0] = true;
//     for (u in G[0]) poss.add(u);
//     while (cleaf < k && poss.size > ptr) {
//         var u = poss[ptr];
//         used[u] = true;
//         leaf[u] = true;
//         ++cleaf;
//         for (v in G[u]) {
//             if (used[v]) {
//                 ++cnt[v];
//                 ++cnt[u];
//             }
//             if (leaf[v] && cnt[v] > 1) {
//                 leaf[v] = false;
//                 --cleaf;
//             }
//             if (!used[v])
//                 poss.add(v);
//         }
//         ++ptr;
//     }
//     if (cleaf == k) {
//         pr.println("YES");
//         var ans = 0;
//         for (a in used)
//             if (a) ++ans;
//         pr.println(ans);
//         for (v in 0..n - 1)
//             if (used[v]) {
//                 pr.print(v + 1);
//                 pr.print(' ');
//             }
//     } else pr.print("NO");
//     pr.print('\n');
//     return 0;
// }

fun mypow(a_: Long, n_: Long) : Long {
    var a = a_;
    var n = n_;
    var ans = 1L;
    while (n > 0) {
        if (n % 2 == 1L) ans *= a;
        a *= a;
        n /= 2;
    }
    return ans;
}

var N = 262144;
var sum = ArrayList<Long>();
var p = ArrayList<Int>();

fun add(v: Int, vl: Int, vr: Int, x: Int) {
    if (x == 0) return;
    p[v] += x;
    sum[v] += x.toLong() * (vr - vl);
    // pr.print(v);
    // pr.print(' ');
    // pr.print(vl);
    // pr.print(' ');
    // pr.print(vr);
    // pr.print(' ');
    // pr.print(x);
    // pr.print(' ');
    // pr.println(sum[v]);
}

fun push(v: Int, vl: Int, vm: Int, vr: Int) {
    add(v + v, vl, vm, p[v]);
    add(v + v + 1, vm, vr, p[v]);
    p[v] = 0;
}

fun add(l: Int, r: Int, x: Int, v: Int, vl: Int, vr: Int) {
    if (l >= vr || r <= vl) return;
    if (vl >= l && vr <= r) {
        // pr.println("---------");
        // pr.print(vl);
        // pr.print(" ");
        // pr.print(vr);
        // pr.print(" ");
        // pr.println(x);
        // pr.println("---------");
        add(v, vl, vr, x);
        return;
    }
    var vm = (vl + vr) / 2;
    push(v, vl, vm, vr);
    add(l, r, x, v + v, vl, vm);
    add(l, r, x, v + v + 1, vm, vr);
    sum[v] = sum[v + v] + sum[v + v + 1];
}

fun get(l: Int, r: Int, v: Int, vl: Int, vr: Int) : Long {
    if (l >= vr || r <= vl) return 0L;
    if (vl >= l && vr <= r) return sum[v];
    var vm = (vl + vr) / 2;
    push(v, vl, vm, vr);
    return get(l, r, v + v, vl, vm) + get(l, r, v + v + 1, vm, vr);
}

fun solve() : Int {
    var n = sc.nextInt();
    var c = ArrayList<Int>();
    for (i in 0..n - 1) {
        c.add(sc.nextInt());
    }
    for (i in 0..2 * N) {
        sum.add(0);
        p.add(0);
    }
    var q = sc.nextInt();
    var query = ArrayList<ArrayList<Pair<Int, Int>>>();
    for (i in 0..n - 1) {
        query.add(ArrayList<Pair<Int, Int>>());
    }
    for (i in 0..q - 1) {
        var l = sc.nextInt() - 1;
        var r = sc.nextInt() - 1;
        query[r].add(Pair(l, i));
    }
    var ans = ArrayList<Long>();
    for (i in 0..q - 1)
        ans.add(0);
    var st = ArrayList<Int>();
    st.add(-1);
    for (i in 0..n - 1) {
        while (st.size > 1 && c[st[st.size - 1]] < c[i]) {
            var from = st[st.size - 2] + 1;
            var to = st[st.size - 1];
            var d = c[to];
            add(from, to + 1, -d, 1, 0, N);
            st.removeAt(st.size - 1);
        }
        var from = st[st.size - 1] + 1;
        var to = i;
        var d = c[i];
        add(from, to + 1, d, 1, 0, N);
        st.add(i);
        // for (j in st) {
        //     pr.print(j);
        //     pr.print(' ');
        // }
        // pr.println();
        for (que in query[i]) {
            var l = que.first;
            var r = i;
            var ind = que.second;
            ans[ind] = get(l, r + 1, 1, 0, N);
        }
    }
    for (v in ans) {
        pr.print(v);
        pr.print(' ');
    }
    pr.println();
    return 0;
}

fun main() {
    var t = 1;//sc.nextLong();
    while (t > 0) {
        solve();
        --t;
    }
    pr.close();
}




class FastScanner {
    companion object {
        val input: InputStream = System.`in`
        val buffer = ByteArray(1024) { 0 }
        fun isPrintableChar(c: Int): Boolean = c in 33..126
    }

    var ptr = 0
    var buflen = 0
    private fun hasNextByte(): Boolean {
        if (ptr < buflen) {
            return true
        } else {
            ptr = 0
            buflen = input.read(buffer)
            if (buflen <= 0) {
                return false
            }
        }
        return true
    }

    private fun readByte(): Int = if (hasNextByte()) buffer[ptr++].toInt() else -1

    private fun skipUnprintable() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr].toInt())) ptr++
    }

    fun hasNext(): Boolean {
        skipUnprintable()
        return hasNextByte()
    }

    fun next(): String {
        if (!hasNext()) throw NoSuchElementException()
        val sb = StringBuilder()
        var b = readByte()
        while (isPrintableChar(b)) {
            sb.appendCodePoint(b)
            b = readByte()
        }
        return sb.toString()
    }

    fun nextInt(): Int {
        if (!hasNext()) throw NoSuchElementException()
        var n = 0
        var b = readByte()
        // '-' = 45
        val minus = b == 45
        if (minus) {
            b = readByte()
        }

        // '0' = 48 '9' = 57
        if (b !in 48..57) {
            throw NumberFormatException()
        }

        while (true) {
            if (b in 48..57) {
                n *= 10
                n += b - 48
            } else if (b == -1 || !isPrintableChar(b)) {
                return if (minus) -n else n
            } else {
                throw NumberFormatException()
            }
            b = readByte()
        }
    }

    fun nextLong(): Long {
        if (!hasNext()) throw NoSuchElementException()
        var n = 0L
        var b = readByte()
        // '-' = 45
        val minus = b == 45
        if (minus) {
            b = readByte()
        }

        // '0' = 48 '9' = 57
        if (b !in 48..57) {
            throw NumberFormatException()
        }

        while (true) {
            if (b in 48..57) {
                n *= 10
                n += b - 48
            } else if (b == -1 || !isPrintableChar(b)) {
                return if (minus) -n else n
            } else {
                throw NumberFormatException()
            }
            b = readByte()
        }
    }

    fun nextDouble(): Double = next().toDouble()
}