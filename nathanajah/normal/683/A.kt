fun main(args: Array<String>) {
    val (a, x, y) = readLine()!!.split(' ').map(String::toInt)
    if (0 < x && x < a && 0 < y && y < a) {
        println(0)
    } else if (x < 0 || y < 0 || x > a || y > a) {
        println(2)
    } else {
        println(1)
    }
}