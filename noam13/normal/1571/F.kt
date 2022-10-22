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
    fun abs(x: Int):Int = if(x<0) -x else x
    var (n,m) = readInts()
    var res = IntArray(n)
    var cur = 0
    var a = arrayListOf<Pair<Int, Int>>()
    var bad = false
    var sum = 0
    for(i in 0..n-1){
        var (k,t) = readInts()
        if (t==1){
            if (cur + k > m) {
                bad = true
                break
            }
            res[i] = cur
            cur += k
        }
        else {
            a.add(Pair(k, i))
            sum += k
        }
    }
    //var arr = a.sortedWith(compareBy({ -it.first }))
    var left = m - cur
    if (sum > left) bad = true
    if (!bad && sum > 0){
        var sz = a.size
        var dp = Array<IntArray>(sz+1, {IntArray(left+1)})
        dp[0][0] = 1
        for(i in 0..sz-1){
            var k = a[i].first
            for(l in 0..left) {
                if(dp[i][l]!=0){
                    if (l+k<=left) {
                        dp[i+1][l+k] = 1
                    }
                    dp[i+1][l] = -1
                }
            }
        }
        //println(dp[sz].joinToString(" "))
        var amt = -1
        for(x in 0..((left+1)/2) ){
            if (dp[sz][x]!=0 && sum-x<=left/2){
                amt = x
            }
        }
        if (amt == -1) bad = true
        else{
            var took = IntArray(sz){0}
            var c0 = cur
            for(i in 0..sz-1){
                if (dp[sz-i][amt]==1){
                    var p = a[sz-i-1]
                    amt -= p.first
                    res[p.second] = c0
                    c0 += 2*p.first
                    took[sz-i-1] = 1
                }
            }
            var c1 = cur + 1
            for(i in 0..sz-1) if(took[i]==0){
                var p = a[i]
                res[p.second] = c1
                c1 += 2*p.first
            }
        }
    }
    if (bad) println(-1)
    else println(res.map({x -> x+1}).joinToString(" "))
    
    
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