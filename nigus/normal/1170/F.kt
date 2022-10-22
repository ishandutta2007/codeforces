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


var q = 0

val MAXN = 600000
var DX = arrayOf(1,-1,0,0)
var DY = arrayOf(0,0,1,-1)
var mark = Array(MAXN){0}

val C: ArrayList<ArrayList<Int>> = ArrayList<ArrayList<Int>>()
//val M: HashMap<Long,Int> = HashMap<Long,Int>()
var s = ""

var A: List<Int> = emptyList()
var nex = Array(MAXN){0}
var B = Array(MAXN){0}
val ANS: ArrayList<ArrayList<Int>> = ArrayList<ArrayList<Int>>()
var CS = Array(MAXN){0.toLong()}
var N = 0
var K = 0
var M = 0

fun abs(x: Long): Long{
    if(x < 0)return -x
    return x
}

fun eq(l: Int, r: Int): Long{
    var L = l
    var R = l+(M+1)/2
    while (L < R-1){
        var mid = (L+R)/2
        var inc: Long = abs(CS[mid+1] - CS[l] - (mid-l+1).toLong() * B[mid].toLong())
       // println(mid.toString() + " " + inc.toString())
        if(inc <= K.toLong()){
            L = mid
        }
        else{
            R = mid
        }
    }


    var ans: Long = abs(CS[L+1] - CS[l] - (L-l+1).toLong() * B[L].toLong())
    ans += abs(CS[r+1] - CS[L+1] - (r-L).toLong() * B[L].toLong())

    var inc: Long = abs(CS[L+1] - CS[l] - (L-l+1).toLong() * B[L].toLong())
    var lft = L-l+1
    var bal = r-l+1-2*lft

    /*
    if(bal > B[L+1] - B[L]){
        bal = B[L+1] - B[L]
    }
*/
    if(bal > 0) {

        ans -= ((K.toLong() - inc) / lft.toLong()) * bal.toLong()
        if(K == 1000000000 && ((K.toLong() - inc) / lft.toLong()) * bal.toLong() > 0){
         //   println(((K.toLong() - inc) / lft.toLong()) * bal.toLong())
        }
    }

    return ans
}

fun main(args: Array<String>) {


    var (n, m, k) = readInts()
    N = n
    A = readInts()
    K = k
    M = m
    for (i in 0 until n){
        B[i] = A[i]
    }
    B.sort()

    for(i in 0 until n){
        B[i] = B[MAXN-n+i]
        CS[i+1] = CS[i] + B[i].toLong()
    }

    var ans: Long = big*big

    for (i in 0 until n-m+1){
            var temp: Long = eq(i,i+m-1)
            if(temp < ans){
                ans = temp
            }
    }
    if(m == 1){
        println(0)
    }
    else {
        println(ans)
    }
}