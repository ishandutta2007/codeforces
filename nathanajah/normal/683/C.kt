import kotlin.comparisons.*;
fun main(args: Array<String>) {
    val arr = readLine()!!.split(' ').map(String::toInt)
    val arr2 = readLine()!!.split(' ').map(String::toInt)
    var arr3 = Array<Int>(3000, {i -> 0})
    for (i in 1..arr[0]) {
        arr3[arr[i] + 1000] = arr3[arr[i] + 1000] + 1
    }
    for (i in 1..arr2[0]) {
        arr3[arr2[i] + 1000] = arr3[arr2[i] + 1000] + 1
    }
    var num = 0
    for (i in arr3) {
        if (i == 1) {
            num++
        }
    }
    print(num)
    for (i in arr3.indices) {
        if( arr3[i] == 1) {
            print(" ")
            print(i - 1000)
        }
    }
    println()
}