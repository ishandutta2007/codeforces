// taken from purplecrayon
import java.util.*


/** IO */
//@JvmField val ONLINE_JUDGE = System.getProperty("ONLINE_JUDGE") != null
//const val PATH = "src/main/resources/"
//@JvmField val INPUT = File(PATH + "input.txt").inputStream()
//@JvmField val OUTPUT = File(PATH + "output.txt").outputStream()
@JvmField
val INPUT = System.`in`
@JvmField
val OUTPUT = System.out

const val _BUFFER_SIZE = 1 shl 16
@JvmField
val _buffer = ByteArray(_BUFFER_SIZE)
@JvmField
var _bufferPt = 0
@JvmField
var _bytesRead = 0

tailrec fun readChar(): Char {
    if (_bufferPt == _bytesRead) {
        _bufferPt = 0
        _bytesRead = INPUT.read(_buffer, 0, _BUFFER_SIZE)
    }
    return if (_bytesRead < 0) Char.MIN_VALUE
    else {
        val c = _buffer[_bufferPt++].toChar()
        if (c == '\r') readChar() else c
    }
}

fun readLine(): String? {
    var c = readChar()
    return if (c == Char.MIN_VALUE) null
    else buildString {
        while (c != '\n' && c != Char.MIN_VALUE) {
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

val MOD = 1000000007L;
val MAX = 100100;
var fact = ArrayList<Long>();
var inv = ArrayList<Long>();

fun comp() {

    fun binexp(a: Long, b: Int): Long {
        if (b == 0) return 1L;
        if (b == 1) return a % MOD;
        if (b % 2 == 1) return (a * binexp(a, b - 1)) % MOD;
        return binexp((a * a) % MOD, b / 2);
    }

    fact.add(1);
    inv.add(1);
    for (i in 1..MAX) {
        fact.add((fact[i - 1] * (i.toLong())) % MOD);
        inv.add(binexp(fact[i], MOD.toInt() - 2));
    }

}

fun choose(a: Int, b: Int): Long {
    var res = (fact[a] * inv[a - b]) % MOD;
    res = (res * inv[b]) % MOD;
    return res;
}

fun cnt(two: Int, three: Int, five: Int, seven: Int, size: Int): Long {

    var ca = 0L;

    for (four in 0..(two/2)) {
    for (nine in 0..(three/2)) {
    var maxsix = kotlin.math.min(two - four * 2, three - nine * 2);
    for (six in 0..maxsix) {
    var maxeight = (two - (four * 2) - six) / 3;
    for (eight in 0..maxeight) {

        var tw = two - six - four * 2 - eight * 3;
        var th = three - six - nine * 2;

        var tot = tw + th + four + five + six + seven + eight + nine;
        var one = size - tot;
        if (tot > size) continue;

        var cv = fact[size];

        cv *= inv[one]; cv %= MOD;
        cv *= inv[tw]; cv %= MOD;
        cv *= inv[th]; cv %= MOD;
        cv *= inv[four]; cv %= MOD;
        cv *= inv[five]; cv %= MOD;
        cv *= inv[six]; cv %= MOD;
        cv *= inv[seven]; cv %= MOD;
        cv *= inv[eight]; cv %= MOD;
        cv *= inv[nine]; cv %= MOD;

        ca += cv;

    } } } }

    return ca;
}

fun main() {

    comp();

    var two = 0;
    var three = 0;
    var five = 0;
    var seven = 0;

    var (m, k) = readLongs();
    var temp = m;

    while (m % 2 == 0L) {
        m = m / 2;
        two++;
    }
    while (m % 3 == 0L) {
        m = m / 3;
        three++;
    }
    while (m % 5 == 0L) {
        m = m / 5;
        five++;
    }
    while (m % 7 == 0L) {
        m = m / 7;
        seven++;
    }

    if (m != 1L) {
        println("-1");
        return;
    }

    var l = 1;
    var ccnt = 0L;
    while (true) {
        var cv = cnt(two, three, five, seven, l);
        if (ccnt + cv >= k) break;
        ccnt += cv;
        l++;
    }

    var ds = Array<Array<Int>>(11) {Array<Int>(4) {0} };
    for (i in 1..9) {
        var temp = i;
        while (temp % 2 == 0) {
            ds[i][0]++;
            temp /= 2;
        }
        while (temp % 3 == 0) {
            ds[i][1]++;
            temp /= 3;
        }
        while (temp % 5 == 0) {
            ds[i][2]++;
            temp /= 5;
        }
        while (temp % 7 == 0) {
            ds[i][3]++;
            temp /= 7;
        }
    }

    for (i in 1..l) {

        for (d in 1..9) {
            var ok = (ds[d][0] <= two && ds[d][1] <= three &&
                      ds[d][2] <= five && ds[d][3] <= seven);
            if (!ok) continue;
            var cva = cnt(two-ds[d][0], three-ds[d][1],
                        five-ds[d][2], seven-ds[d][3],
                        l - i);
            if (ccnt + cva >= k) {
                print(d);
                two -= ds[d][0]; three -= ds[d][1]; five -= ds[d][2]; seven -= ds[d][3];
                break;
            }
            ccnt += cva;
        }

    }

}