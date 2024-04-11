import java.util.*

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLong() = readLn().toLong() // single long
private fun readLongs() = readStrings().map { it.toLong() } // list of longs

val big: Long = 1000000007

fun sum(a: Int, b: Int): Int { // example function
    var c = a+b
    return c
}

var n = 0
var m = 0
var q = 0

val MAXN = 300000
var DX = arrayOf(1,-1,0,0)
var DY = arrayOf(0,0,1,-1)
var mark = Array(MAXN){0}

val C: ArrayList<ArrayList<Int>> = ArrayList<ArrayList<Int>>()
val M: HashMap<Long,Int> = HashMap<Long,Int>()
var s = ""


fun main(args: Array<String>) {

    var q = readInt()
    for (i in 0 until q){
        var (x, y) = readLongs()
        var a = x-1
        if (y-1 < x-1){
            a = y-1
        }
        var b = x-a
        var c = y-a
        println(a.toString() + " " + b.toString() + " "+ c.toString())
    }

}