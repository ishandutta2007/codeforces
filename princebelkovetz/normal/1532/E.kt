import java.lang.Integer.max



fun main() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(" ").map { it.toInt() }
    val ans = mutableListOf<Int>();
    var sum: Long = 0
    for (x in a)
        sum += x
    var pre = IntArray(n)
    var suf = IntArray(n)
    for (i in 1 until n){
        pre[i] = max(pre[i - 1], a[i - 1])
        suf[n - 1 - i] = max(suf[n - i], a[n - i])
    }
    for (i in 0 until n){
        val mx = max(pre[i], suf[i])
        if (mx.toLong() == sum - a[i] - mx)
            ans.add(i + 1)
    }
    println(ans.size)
    for (x in ans)
        print("$x ")
    println()

}