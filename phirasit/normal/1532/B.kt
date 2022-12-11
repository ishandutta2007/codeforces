
fun main() {
  val n = readLine()!!.toInt()
  for (i in 1..n) {
    val (a, b, k) = readLine()!!.split(" ".toRegex()).map { it.toLong() }
    val ans = (k+1) / 2 * a - k / 2 * b
    println(ans)
  }
}