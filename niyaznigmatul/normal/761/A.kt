import java.util.*
import java.io.*

fun main(args: Array<String>) {
  val sc = Scanner(System.`in`)
  val a = sc.nextInt()
  val b = sc.nextInt()
  for (i in 1..200) {
    for (j in i..200) {
      var even = 0
      var odd = 0
      for (k in i..j) {
        if (k % 2 == 0) even++ else odd++
      }
      if (even == a && odd == b) {
        println("YES")
        return;
      }
    }
  }
  println("NO")
}