fun main() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(" ").map { it.toInt() }
    if (a.max() == 0) {
        println("EASY")
    } else {
        println("HARD")
    }
}