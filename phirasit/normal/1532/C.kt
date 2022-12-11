
fun main() {
  val t = readLine()!!.toInt()
  for (i in 1..t) {
    val (n, k) = readLine()!!.split(" ".toRegex()).map { it.toInt() }
    val ans = (0..n-1).map { (it % k + 'a'.toInt()).toChar() }.joinToString("")
    println (ans)
  }
}