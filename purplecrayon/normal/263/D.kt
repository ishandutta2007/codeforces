import kotlin.math.*;
import java.util.*;
import kotlin.system.exitProcess

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles


fun dfs(c: Int, p: IntArray, k: Int, depth: IntArray, adj: Array<MutableList<Int>>) {
    if (p[c] == -1) depth[c] = 0;
    else depth[c] = depth[p[c]]+1;

    for (nxt in adj[c]) {
        if (depth[nxt] == -1) {
            p[nxt] = c;
            dfs(nxt, p, k, depth, adj);
        } else if (depth[c] > depth[nxt]) {
            var sz = depth[c]-depth[nxt]+1;
            if (sz <= k) continue;
            println(sz);
            var ans = IntArray(sz){ _ -> -1; }

            var ptr = 0;
            var cur = c;
            while (true) {
                ans[ptr] = cur+1;
                ptr++;

                if (cur == nxt) break;
                cur = p[cur];
            }
            println(ans.joinToString(" "));
            exitProcess(0);
        }
    }
}
fun solve() {
    var (n, m, k) = readInts();
    var adj = Array<MutableList<Int>>(n){ _ -> mutableListOf<Int>(); }
    for (i in 0 until m) {
        var (a, b) = readInts();
        a--; b--;
        adj[a].add(b);
        adj[b].add(a);
    }
    var depth = IntArray(n){ _ -> -1; };
    var par = IntArray(n){ _ -> -1; };
    dfs(0, par, k, depth, adj);
}
fun main() {
//    val T = readInt();
    val T = 1;
    for (test in 0 until T) {
        solve();
    }
}