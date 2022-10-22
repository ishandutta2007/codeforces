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
    var t = readInt()
    for(it in 1..t){
        var n = readInt();
        var mini = 0
        var maxi = INF
        for (i in 1..n){
            var (s,t,r) = readStrings()
            var cnt = 0
            var sz = min(s.length, t.length)
            for(j in 1..sz){
                if (s[s.length-j]!=t[t.length-j]) break;
                cnt++;
            }
            if (r=="1"){
                maxi = min(maxi, cnt)    
            }
            else{
                mini = max(mini, cnt+1)
            }
        }
        if (mini <= maxi){
            println(maxi-mini+1)
            println((mini..maxi).joinToString(" "))
        }
        else println(0)
    }
    
    
    
    // for(i in 1..t){
    //     var (a,b) = readInts()
    //     println(a+b)
    // }

//     var qur = Array(q, {i -> Pair(-1, -1)})
//     var dec = IntArray(n+1){INF}
//     var inds = LongArray(n+1){-1}
//     var qq = qur.sortedWith(compareBy({ it.second }, { it.first }))
//     for(i in qur.indices){
//         val p = readInts()
//         qur[i] = Pair(i, p[1]-1)
//         st[i] = p[0] - 1
//     }
    

    
    

//     println(ans.joinToString(" "))

}