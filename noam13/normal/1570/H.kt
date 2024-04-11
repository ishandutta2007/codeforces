import kotlin.text.*
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLong() = readLn().toLong() // single long
private fun readLongs() = readStrings().map { it.toLong() } // list of longs

const val MOD = 998244353
const val INF = (1e18).toLong()

fun YN(b: Boolean) : String { return if (b) "YES" else "NO"  }
fun add(a: Int, b: Int): Int {
    var v = a+b
    if (v>=MOD) v-=MOD
    return v
}
fun sub(a: Int, b: Int): Int {
    var v = a-b
    if (v<0) v+=MOD
    return v
}
fun mul(a: Int, b: Int) = ((a.toLong()*b.toLong())%MOD.toLong()).toInt()
fun gcd(a: Int, b: Int) : Int = if (b == 0) a else gcd(b,a%b)
fun min(x: Int, y :Int) :Int = if(x>y) y else x
fun max(x: Int, y :Int) :Int = if(x<y) y else x


const val max = 8 * 5 + 10
fun main() {
    var (n,m) = readInts()
    var sz: Int = 1
    var next = Array(max, {i -> IntArray(26){-1}})
    var isend = Array(max, {i -> IntArray(26){-1}})
    fun getNext(cur: Int, v:Int):Int{
        return next[cur][v]
    }
    var ss = Array(n, {readLn()})
    for(i in 0..n-1){
        var s = ss[i]
        var cur:Int = 0
        var l = s.length
        if(l > 1) for(c in 0..l-2){
            var v = s[c].toByte().toInt()-'a'.toByte().toInt()
            if (next[cur][v] == -1) next[cur][v] = sz++
            cur = next[cur][v]
        } 
        var v = s[l-1].toByte().toInt()-'a'.toByte().toInt()
        isend[cur][v] = 0
    }
    val L = 6
    var mat = Array(L*sz, {IntArray(L*sz, {0})})
    for(l in 1..L-1) for(a in 0..sz-1) mat[a+l*sz][a+(l-1)*sz] = 1
    for(a in 0..sz-1) for(ind in 0..n-1){
        var s = ss[ind]
        var l = s.length
        var dp = Array(l+1, {IntArray(sz, {0})})
        dp[0][a] = 1
        for(i in 0..l-1){
            var v = s[i].toByte().toInt()-'a'.toByte().toInt()
            for(cur in 0..sz-1){
                if (next[cur][v]!=-1) dp[i+1][next[cur][v]] += dp[i][cur]
                if (isend[cur][v]!=-1) dp[i+1][0] += dp[i][cur]
            }
        }
        for(cur in 0..sz-1) mat[a][cur+(l-1)*sz] += dp[l][cur]
    }
    //for(i in 0..sz*sz-1) println(mat[i].joinToString(" "))
    fun mul(A:Array<IntArray>, B:Array<IntArray>): Array<IntArray>{
        var n = A.size
        var C = Array(n, {i -> IntArray(n, {j -> 0})})
        for(i in 0..n-1) for(k in 0..n-1) if(A[i][k]!=0) for(j in 0..n-1) if(B[k][j]!=0){
            C[i][j] = add(C[i][j], mul(A[i][k], B[k][j]))
        }
        return C
    }
    
    var SZ = mat.size
    var ans = Array(SZ, {i -> IntArray(SZ, {j -> (if (i == j) 1 else 0) })})
    while(m>0){
        if (m%2==1){
            ans = mul(ans, mat)
        }
        m /= 2
        mat = mul(mat, mat)
    }
    println(ans[0][0])
    
    
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