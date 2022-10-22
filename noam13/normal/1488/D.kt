/**
 * You can edit, run, and share this code. 
 * play.kotlinlang.org 
 */

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toLong() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toLong() } // list of ints


fun main() {
    var t = readLine()!!.toInt()
    fun min(x: Int, y :Int) :Int = if(x>y) y else x
    fun max(x: Int, y :Int) :Int = if(x<y) y else x
    while(t-- > 0){
        var (n, s) = readInts()
        var ans:Long = 0
        var l:Long = 1
        var r:Long = s+1
        while(l<r){
            var mid:Long = (l+r)/2
            var cur:Long = mid
            var cnt:Long = 0
            var sum:Long = 0
            while(cur>1){
                sum += cur
                cur = (cur+1)/2
                cnt++
                if (cnt == n) break
            }
            sum += n-cnt
            if (sum<=s) {
                ans = mid
                l = mid+1
            }
            else r = mid
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