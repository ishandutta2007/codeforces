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

    n = readInt()
    var A = readLongs()
    var bigg = (-1).toLong()
    var biggg = (-1).toLong()
    var ans = 0
    for (i in 0 until n){
        if (A[i] >= bigg){
            biggg = bigg
            bigg = A[i]
        }
        else{
            if(A[i] >= biggg){
                biggg = A[i]
            }
            else{
                ans += 1
            }
        }
    }
    println(ans)

}