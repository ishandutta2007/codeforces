fun main() {
    val (Y, B, R) = readLine()!!.split(" ").map { it.toInt() }
    println(3 * minOf(Y + 1, B, R - 1))
}