import java.util.*


/** IO */
//@JvmField val ONLINE_JUDGE = System.getProperty("ONLINE_JUDGE") != null
//const val PATH = "src/main/resources/"
//@JvmField val INPUT = File(PATH + "input.txt").inputStream()
//@JvmField val OUTPUT = File(PATH + "output.txt").outputStream()
@JvmField val INPUT = System.`in`
@JvmField val OUTPUT = System.out

const val _BUFFER_SIZE = 1 shl 16
@JvmField val _buffer = ByteArray(_BUFFER_SIZE)
@JvmField var _bufferPt = 0
@JvmField var _bytesRead = 0

tailrec fun readChar(): Char {
    if(_bufferPt == _bytesRead) {
        _bufferPt = 0
        _bytesRead = INPUT.read(_buffer, 0, _BUFFER_SIZE)
    }
    return if(_bytesRead < 0) Char.MIN_VALUE
    else {
        val c = _buffer[_bufferPt++].toChar()
        if (c == '\r') readChar() else c
    }
}
fun readLine(): String? {
    var c = readChar()
    return if(c == Char.MIN_VALUE) null
    else buildString {
        while(c != '\n' && c != Char.MIN_VALUE) {
            append(c)
            c = readChar()
        }
    }
}
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

const val INF = (1e9).toInt()+10;

class MinCostMaxFlow {
    lateinit var found: BooleanArray
    var N = 0
    lateinit var cap: Array<IntArray>
    lateinit var flow: Array<IntArray>
    lateinit var cost: Array<IntArray>
    lateinit var dad: IntArray
    lateinit var dist: IntArray
    lateinit var pi: IntArray
    fun search(source: Int, sink: Int): Boolean {
        var source = source
        Arrays.fill(found, false)
        Arrays.fill(dist, INF)
        dist[source] = 0
        while (source != N) {
            var best = N
            found[source] = true
            for (k in 0 until N) {
                if (found[k]) continue
                if (flow[k][source] != 0) {
                    val `val` = dist[source] + pi[source] - pi[k] - cost[k][source]
                    if (dist[k] > `val`) {
                        dist[k] = `val`
                        dad[k] = source
                    }
                }
                if (flow[source][k] < cap[source][k]) {
                    val `val` = dist[source] + pi[source] - pi[k] + cost[source][k]
                    if (dist[k] > `val`) {
                        dist[k] = `val`
                        dad[k] = source
                    }
                }
                if (dist[k] < dist[best]) best = k
            }
            source = best
        }
        for (k in 0 until N) pi[k] = Math.min(pi[k] + dist[k], INF)
        return found[sink]
    }

    fun getMaxFlow(cap: Array<IntArray>, cost: Array<IntArray>, source: Int, sink: Int): IntArray {
        this.cap = cap
        this.cost = cost
        N = cap.size
        found = BooleanArray(N)
        flow = Array(N) { IntArray(N) }
        dist = IntArray(N + 1)
        dad = IntArray(N)
        pi = IntArray(N)
        var totflow = 0
        var totcost = 0
        while (search(source, sink)) {
            var amt = INF
            run {
                var x = sink
                while (x != source) {
                    amt = Math.min(
                        amt,
                        if (flow[x][dad[x]] != 0) flow[x][dad[x]] else cap[dad[x]][x] - flow[dad[x]][x]
                    )
                    x = dad[x]
                }
            }
            var x = sink
            while (x != source) {
                if (flow[x][dad[x]] != 0) {
                    flow[x][dad[x]] -= amt
                    totcost -= amt * cost[x][dad[x]]
                } else {
                    flow[dad[x]][x] += amt
                    totcost += amt * cost[dad[x]][x]
                }
                x = dad[x]
            }
            totflow += amt
        }
        return intArrayOf(totflow, totcost)
    }
}


fun solve() {
    var (n1, n2, m) = readInts();

    var S = n1+n2;
    var T = n1+n2+1;
    var N = n1+n2+2;

    var cap = Array<IntArray>(N){ IntArray(N){ 0 } };
    var cost = Array<IntArray>(N){ IntArray(N){ 0 } };

    fun addEdge(a: Int, b: Int, _cap: Int, _cost: Int) {
        cap[a][b] = _cap;
        cost[a][b] = _cost;
    }
    var k = readInts();

    val MAXC = (1e6).toInt() + 10; // max cost


    for (i in 0 until n1) {
        addEdge(S, i, 1, MAXC-k[i]);
    }
    var deg = IntArray(n2){ 0 };
    for (i in 0 until m) {
        var (a, b) = readInts();
        a--; b--;
        addEdge(a, b+n1, 1, 0);
        deg[b]++;
    }
    for (i in 0 until n2) {
        addEdge(i+n1, T, deg[i]-1, 0);
    }
    var flower = MinCostMaxFlow();
    var ans = flower.getMaxFlow(cap, cost, S, T);

    var extra = ans[0]*MAXC;
    var realCost = ans[1]-extra;

    for (i in 0 until n1) realCost += k[i];
    println(realCost);
}
fun main() {
//    val T = readInt();
    val T = 1;
    repeat(T) {
        solve();
    }
}