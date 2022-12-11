
fun main() {
  val n = readLine()!!.toInt()
  val arr: Array<Long> = readLine()!!.split(" ".toRegex()).map { it.toLong() }.toTypedArray()

  val mx = arr.fold(Pair<Long, Long>(0L, 0L), { mx, i ->
    if (i > mx.first) Pair(i, mx.first)
    else if (i > mx.second) Pair(mx.first, i)
    else Pair(mx.first, mx.second)
  })

  val sum: Long = arr.fold(0L, { acc, i -> acc + i })

  val ans = (1..n).filter { i ->
    sum - arr[i-1] == 2 * (if (arr[i-1] == mx.first) mx.second else mx.first)
  }

  println(ans.size)
  println(ans.joinToString(" "))
}