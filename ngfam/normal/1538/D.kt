import kotlin.math.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs

fun gcd(x: Int, y: Int): Int {
    if (x == 0) return y;
    return gcd(y % x, x);
}

fun countPrimeFactor(x: Int): Int {
    var i = 2;
    var temp = x;
    var ans = 0;
    while(i * i <= x) {
        while(temp % i == 0) {
            ans += 1;
            temp /= i;
        }
        i++;
    }
    if (temp > 1) ans++;
    return ans;
}

fun main() {
    val ntest = readInt();
    repeat(ntest) {
        val (a, b, k) = readInts();

        if (k == 1) {
            if ((a % b == 0 || b % a == 0) && a != b){
                println("YES");
            }
            else {
                println("NO");
            }
        }
        else {
            val wa = countPrimeFactor(a);
            val wb = countPrimeFactor(b);
            if (wa + wb >= k) {
                println("YES");
            }
            else {
                println("NO");
            }
        }
    }
}