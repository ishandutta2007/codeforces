import java.util.*

/**
 * Created by Borys Minaiev on 06.12.17.
 */

fun main(args : Array<String>) = with(Scanner(System.`in`)) {
    val n = nextInt()
    val a = List(n) {i -> nextInt()}
    var res = 360
    for (i in a.indices)
        for (j in i..a.lastIndex) {
            val sum = Math.abs(180 - a.subList(i, j).sum())
            res = Math.min(sum, res)
        }
    println(res * 2)
}