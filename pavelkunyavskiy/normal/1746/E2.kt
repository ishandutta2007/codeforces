import kotlin.random.*

fun main() {
    val n = readInt()
    //while (true) {
    var ifTrue = (1..n).toList()
    var ifFalse = emptyList<Int>()
    var ops = 0
    while (ifTrue.size + ifFalse.size > 2) {
        ops++
        val fSize = ifFalse.size / 2
        val s = ifFalse.subList(0, fSize) + ifTrue.subList(0, (ifTrue.size + ifFalse.size + 1) / 2 - fSize)
        //System.err.println("$ops ${ifFalse.size} ${ifTrue.size}")
        println("? ${s.size} " + s.joinToString(" "))
        System.out.flush()
        val ss = when (readLn()) {
            //when (if (Random.nextBoolean()) "YES" else "NO") {
            "NO" -> (ifFalse + ifTrue).toSet() - s.toSet()
            "YES" -> s.toSet()
            else -> TODO()
        }
        val newIfTrue = ifFalse.filter { it in ss } + ifTrue.filter { it in ss }
        val newIfFalse = ifTrue.filter { it !in ss }

        ifTrue = newIfTrue
        ifFalse = newIfFalse
    }
    //System.err.println("ops = $ops")
    //require(ops <= 53)
    //}

    val all = ifTrue + ifFalse
    require(all.size <= 2)
    for (i in all) {
        println("! $i")
        System.out.flush()
        if (readLn() == ":)") break
    }
    //System.err.println("ops = $ops")
}

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLongs() = readStrings().map { it.toLong() }
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }