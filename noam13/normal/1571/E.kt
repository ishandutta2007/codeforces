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
    fun vv(a: Char, b: Char):Int = if(a==b) 0 else 1
    var t = readInt()
    for(it in 1..t){
        var n = readInt();
        var s = readLn().toCharArray()
        
        var a = readLn() + "000"
        var ans = 0
        var bad = false
        for(i in 0..n-4){
            if (a[i]=='0') continue;
            if (a[i+1]=='1' || a[i+3]=='1') {
                bad = true
                break;
            }
            var v1 = vv(s[i],'(')+vv(s[i+1],')')+vv(s[i+2],'(')+vv(s[i+3],')')
            var v2 = vv(s[i],'(')+vv(s[i+1],'(')+vv(s[i+2],')')+vv(s[i+3],')')
            if (v1 < v2 || a[i+2]=='1'){
                ans += v1
                s[i] = '('
                s[i+1] = ')'
                s[i+2] = '('
                s[i+3] = ')'
            }
            else{
                ans += v2
                s[i] = '('
                s[i+1] = '('
                s[i+2] = ')'
                s[i+3] = ')'
            }
        }
        if (bad) println(-1)
        else println(ans)
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