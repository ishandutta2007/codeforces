/**
 * You can edit, run, and share this code. 
 * play.kotlinlang.org 
 */

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLong() = readLn().toLong() // single long
private fun readLongs() = readStrings().map { it.toLong() } // list of longs

val INF = 1000000000
fun main() {
    var t = readLine()!!.toInt()
    fun min(x: Int, y :Int) :Int = if(x>y) y else x
    fun max(x: Int, y :Int) :Int = if(x<y) y else x
    while(t-- > 0){
        var n = readInt()
        var arr = readInts()
        var last = IntArray(n+1)
        for(i in arr.indices){
            last[arr[i]] = i
        }
        var vals = IntArray(n+1){-INF}
        vals[0] = n+1
        var cnt = 0
        var ans = 1
        for(i in arr.indices){
            ans = max(ans, 2*cnt)
            while(cnt>0 && vals[cnt]<=i) cnt--
            ans = max(ans, 2*cnt+1)
            var x = arr[i]
            var j = last[x]
            if (j!=i){
                var l = 0
                var r = n
                var pos = 0
                while(l<r){
                    var mid = (l+r)/2
                    if (vals[mid]>j) {
                        pos = mid
                        l = mid + 1
                    }
                    else r = mid
                }
                vals[pos+1] = j
                cnt = max(cnt, pos+1)
            }
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