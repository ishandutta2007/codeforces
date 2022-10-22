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

val MAXN = 600000
var DX = arrayOf(1,-1,0,0)
var DY = arrayOf(0,0,1,-1)
var mark = Array(MAXN){0}

val C: ArrayList<ArrayList<Int>> = ArrayList<ArrayList<Int>>()
val M: HashMap<Long,Int> = HashMap<Long,Int>()
var s = ""

var A: List<Int> = emptyList()
var nex = Array(MAXN){0}
val ANS: ArrayList<ArrayList<Int>> = ArrayList<ArrayList<Int>>()

fun main(args: Array<String>) {

    m = readInt()
    A = readInts()
    n = 0
    for (i in 0 until m){
        if (A[i] == -1){
            nex[n] = n+1
            n += 1
            val temp = ArrayList<Int>()
            ANS.add(temp)
        }
    }
    nex[n-1] = 0
    var prev = n-1
    var a = 0
    for (i in 0 until m){
        if (A[i] == -1){
            nex[prev] = nex[a]
        }
        else{
            ANS[a].add(A[i])
            prev = a
        }

        a = nex[a]

    }

    println(n)
    for (i in 0 until n){
        print(ANS[i].size.toString() + " ")
        for (x in ANS[i]){
            print(x.toString() + " ")
        }
        println("")
    }

}