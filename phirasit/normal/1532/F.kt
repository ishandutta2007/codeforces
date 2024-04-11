fun main() {
  val n = readLine()!!.toInt()
  val str: Array<String> = (1..2*n-2).map { readLine()!! }.toTypedArray()

  val sorted = (0..2*n-3).sortedWith(compareBy({ str[it].length }))

  val a = str[sorted[2*n-4]]
  val b = str[sorted[2*n-3]]

  val candid0 = a.substring(0, 1) + b
  val candid1 = b + a.substring(n-2, n-1)

  val ans1 = check(candid0, n, str)
  val ans2 = check(candid1, n, str)

  val ans = if (ans1.length > 0) ans1 else ans2

  println(ans)
}

fun check(candid: String, n: Int, str: Array<String>): String {
  val prefix = (1..n-1).map { Pair<String, Int>(candid.substring(0, it), it) }.toTypedArray()
  val suffix = (1..n-1).map { Pair<String, Int>(candid.substring(it), -it) }.toTypedArray()

  val sorted = (prefix + suffix).sortedWith(compareBy({ it.first }))

  val ans = Array(2*n-2) { "" }
  val idx = (0..2*n-3).sortedWith(compareBy({ str[it] }))

  for ((x, s) in idx.zip(sorted)) {
    if (str[x] != s.first) {
      return "";
    }
    ans.set(x, if (s.second > 0) "P" else "S")
  }

  return ans.joinToString("")
}