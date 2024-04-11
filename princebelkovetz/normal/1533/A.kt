
fun main() {
    var tt = readLine()!!.toInt()
    while (tt-->0) {
        val (n, k) = readLine()!!.split(" ").map{it.toInt()}
        var ans = 0
        for (i in 0 until n) {
            val (l, r) = readLine()!!.split(" ").map{it.toInt()}
            if (l > k) continue
            ans = maxOf(ans, r - k + 1)
        }
        println(ans)
    }

}