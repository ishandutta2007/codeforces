import scala.io.StdIn.readLine

object Main {

  def gcd(a: Int, b: Int): Int = if (a == 0) b else gcd(b % a, a)

  def main(args: Array[String]): Unit = {
    val ints = readLine().split(" ").map(s => s.toInt)
    val (n, m, z) = (ints(0), ints(1), ints(2))
    val gcf = n * m / gcd(n, m)
    println(z / gcf)
  }
}