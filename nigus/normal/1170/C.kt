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

var A: List<Long> = emptyList()

fun main(args: Array<String>) {

    n = readInt()

    for (i in 0 until n){
        var s = readLn()
        var t = readLn()
        n = s.length
        m = t.length
        var a = 0
        var fail = 0
        for (b in 0 until m){
            if(a >= n){
                fail = 1
                break
            }
            if(s[a].equals(t[b])){
                a += 1
            }
            else{
                if(a >= n-1){
                    fail = 1
                    break
                }
                if(t[b].equals('+') && s[a].equals('-') && s[a+1].equals('-')){
                    a += 2
                }
                else{
                    fail = 1
                    break
                }
            }
        }
        if(a != n){
            fail = 1
        }
        if(fail == 0){
            println("YES")
        }
        else{
            println("NO")
        }
    }


}