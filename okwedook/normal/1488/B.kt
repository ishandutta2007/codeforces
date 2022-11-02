import java.util.*
import java.io.*;
import kotlin.*
import java.io.InputStream
import java.lang.NumberFormatException
import java.lang.StringBuilder
import kotlin.system.exitProcess as exit
import kotlin.math.min as min
import kotlin.math.max as max

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

fun solve() : Int {
    var n = sc.nextInt();
    var k = sc.nextInt();
    var s = sc.next();
    var st = ArrayList<Char>();
    var ans = 0;
    var last = -1;
    for (i in 0..n - 1) {
        if (st.size > 0 && s[i] == ')' && st[st.size - 1] == '(') {
            st.removeAt(st.size - 1);
        } else {
            st.add(s[i]);
        }
        if (st.size == 0) {
            var t = (i - last) / 2;
            
            var d = min(k, max(0, t - 1));
            ++ans;
            ans += d;
            k -= d;
            last = i;
        }
    }
    pr.println(ans);
    return 0;
}

fun main() {
    var t = sc.nextLong();
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