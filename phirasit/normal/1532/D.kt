
fun main() {
  val n = readLine()!!.toInt()
  val arr: Array<Int> = readLine()!!.split(" ".toRegex()).map { it.toInt() }.toTypedArray()
  arr.sort()

  val ans = (0..n-1 step 2).map { arr[it+1] - arr[it] }.fold(0, { acc, i -> acc + i })
  println(ans)
}