import kotlin.comparisons.*;
fun main(args: Array<String>) {
    val n = readLine()!!.toInt()
    val arr = readLine()!!.split(' ').map(String::toInt)
    val arr2 = Array<Int>(n, {i -> 0})
    for (i in 1..n) {
        val ind = n - i
        var position = i - 1
        arr2.set(position, ind + 1)
        for (j in 1..i-1-arr[ind]) {
            val tmp = arr2[position - 1]
            arr2[position - 1] = arr2[position]
            arr2[position] = tmp
            position--
        }
    }
    for (i in arr2) {
        print(" ")
        print(i)
    }
    println()
}