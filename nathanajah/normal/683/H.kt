import kotlin.comparisons.*;
import kotlin.collections.*;
import java.util.*;

fun main(args: Array<String>) {
    val (n2, k) = readLine()!!.split(' ').map(String::toLong)
    val n = n2.toInt()

    var arr = readLine()!!.split(' ').map(String::toInt)
    var arr2 = Array<Int>(n, {i -> i})
    for (i in 0..n-1) {
        arr2.set(i, arr.get(i) - 1)
    }
    var arr4 = Array<Int>(n, {i -> i})
    var visited = Array<Boolean>(n, {i -> false})
    for (i in 0..n-1) {
        if (!visited[i]) {
            var cycle = ArrayList<Int>()
            var x = i
            while (!visited[x]) {
                cycle.add(x)
                visited[x] = true
                x = arr2[x]
            }
            val cycsize = cycle.size
            for (j in 0..cycsize - 1) {
                arr4[cycle[((j + k) % cycsize).toInt()]] = cycle[j]

            }
        }
    }
    for (i in arr4) {
        print(" ")
        print(i + 1)
    }
    println()
}