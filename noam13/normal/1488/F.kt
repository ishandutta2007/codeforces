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
    fun min(x: Int, y :Int) :Int = if(x>y) y else x
    fun max(x: Int, y :Int) :Int = if(x<y) y else x
    var n = readInt()
    var arr = readInts()
    val q = readInt()
    var qur = Array(q, {i -> Pair(-1, -1)})
    var st = IntArray(q)
    var ans = LongArray(q)
    for(i in qur.indices){
        val p = readInts()
        qur[i] = Pair(i, p[1]-1)
        st[i] = p[0] - 1
    }
    var qq = qur.sortedWith(compareBy({ it.second }, { it.first }))
    
    var dec = IntArray(n+1){INF}
    var inds = LongArray(n+1){-1}
    var vals = LongArray(n+1){0}
    var j = 0
    var pt = 0
    for(i in arr.indices){
        // insert arr[i]
        while(j>0 && dec[j]<=arr[i]) j--
        j++
        dec[j] = arr[i]
        inds[j] = i.toLong()
        vals[j] = arr[i] * (i-inds[j-1]) + vals[j-1]
        //println("I: ${i}")
        //println(inds.joinToString(" "))
        while(pt<q && qq[pt].second == i){
            var ind = qq[pt].first
            var x = st[ind]
            var l = 0
            var r = j+1
            var pos = 0
            while(l<r){
                var mid = (l+r)/2
                //println("LR: ${l} ${r} ${mid} ${inds[mid]}")
                if (inds[mid]>=x) {
                    r = mid
                    pos = mid
                }
                else l = mid + 1
            }
            //println("POS: ${pos}")
            var res:Long = vals[j] - vals[pos]
            res += dec[pos] * (inds[pos] - x+1)
            ans[ind] = res
            // println("${qq[pt]}, ${res}") 
            pt++
        }
    }
    println(ans.joinToString(" "))
    // qur.sort()
    
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