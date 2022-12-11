
fun main() {
  val n = readLine()!!.toInt()
  for (i in 1..n) {
    val inp: List<String> = readLine()!!.split(" ".toRegex())
    println(inp[0].toInt() + inp[1].toInt())
  }
}