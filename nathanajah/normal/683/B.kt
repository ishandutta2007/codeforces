import kotlin.comparisons.*;
fun main(args: Array<String>) {
    val (n) = readLine()!!.split(' ').map(String::toInt)
    val arr = Array(n, {i -> readLine()!!.split(' ')})
    val arr2 =  arr.sortedWith(compareBy({it.component2().toString()}));
    for (i in arr2) {
        println(i.component1())
    }
}