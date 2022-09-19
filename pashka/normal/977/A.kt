fun main(args: Array<String>) {
    val (n, k) = readLine()!!.split(" ").map{ it.toInt() }
    var c = n
    repeat(k) {
        c = if (c % 10 > 0) {
            c - 1
        } else {
            c / 10
        }
    }
    println(c)
}