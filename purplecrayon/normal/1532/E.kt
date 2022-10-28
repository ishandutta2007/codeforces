import kotlin.math.min;

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles


fun main() {
    var n = readInt();
    var a = readInts();
    var cnt = IntArray(1000001);
    var sm:Long = 0;
    
    for (i in 0 until n) {
        sm += a[i];
        cnt[a[i]]++; 
    }
    var ans = mutableListOf<Int>()
    for (i in 0 until n) {
        sm -= a[i];
        cnt[a[i]]--;
        
        if (sm/2 < 1000001.toLong() && (sm.toInt()%2) == 0 && cnt[sm.toInt()/2] > 0) {
            ans.add(i+1);
        }
        
        cnt[a[i]]++;
        sm += a[i];
    }
    println(ans.size);
    println(ans.joinToString(" "));
}