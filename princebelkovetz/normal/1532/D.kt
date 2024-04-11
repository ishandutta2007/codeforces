
fun main() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(" ").map { it.toInt() }.sorted()
    var ans = 0;
    for (i in 0 until n / 2) {
        ans += a[i * 2 + 1] - a[i * 2]
    }
    println(ans)

}