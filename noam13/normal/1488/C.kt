/**
 * You can edit, run, and share this code. 
 * play.kotlinlang.org 
 */

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

val MAX = 1001
fun main() {

    var t = readLine()!!.toInt()
    fun min(x: Int, y :Int) :Int = if(x>y) y else x
    fun max(x: Int, y :Int) :Int = if(x<y) y else x
    while(t-- > 0){
        val arr = readLine()!!.split(" ").map { it.toInt() }
        var n = arr[0]
        var x = arr[1]
        var y = arr[2]
        if (x>y) {
            val tmp = x
            x = y
            y = tmp
        }
        var ans = 2 * n
        for(k in x+1..y){
            var v = max(k-2 + min(x-1, k-1-x), n-k + min(n-y, y-k))
            ans = min(ans, v)
        }
        println("${ans}")
        
    }
    
    /*val arr = readLine()!!.split(" ").map { it.toInt() }
    val can = IntArray(MAX)
    var lst: List<Int> = ArrayList()
    for (i in n-1 downTo 0){
        if (can[arr[i]]==0){
            can[arr[i]] = 1
            lst += arr[i]
        }
    }
    lst = lst.reversed()
    println(lst.joinToString(" "))*/
}