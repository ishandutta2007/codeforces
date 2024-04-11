fun main() {
    var (a, b) = readLine()!!.split(" ").map { it.toInt() }
    var c = 0
    while (a <= b) {
        c++
        a *= 3
        b *= 2
    }
    println(c)
}