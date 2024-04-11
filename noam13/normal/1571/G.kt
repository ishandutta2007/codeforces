private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLong() = readLn().toLong() // single long
private fun readLongs() = readStrings().map { it.toLong() } // list of longs


private fun min(x: Long, y :Long) :Long = if(x>y) y else x
private fun max(x: Long, y :Long) :Long = if(x<y) y else x
val INF:Long = 1e18.toLong()

var maxi = LongArray(0)
fun modify(x: Int, l: Int, r: Int, i: Int, v: Long) {
    if (l+1 == r) {
        maxi[x] = max(maxi[x], v)
        return
    }
    val y = (l + r) / 2
    if (i < y) {
        modify(x + x, l, y, i, v)
    }
    else{
        modify(x + x + 1, y, r, i, v)
    }
    maxi[x] = max(maxi[x+x], maxi[x+x+1])
}
 
fun getMax(x: Int, l: Int, r: Int, ll: Int, rr: Int) : Long {
    if (r <= ll || rr <= l) {
        return -INF
    }
    if (ll <= l && r <= rr) {
        return maxi[x]
    }
    val y = (l + r) /2
    var res = max(getMax(x + x, l, y, ll, rr), getMax(x + x + 1, y, r, ll, rr))
    return res
}


fun main() {
    var (n,m) = readInts()
    var ps = arrayListOf<Pair< Pair<Int, Int>, Int>>()
    ps.add(Pair(Pair(0,m), 0))
    for(i in 1..n){
        var k = readInt()
        var a = readInts()
        var b = readInts()
        for(j in 0..k-1){
            ps.add(Pair(Pair(i,b[j]), a[j]) )
        }
    }
    ps.sortWith(compareBy({ -it.first.second }, {it.first.first}))
    //println(ps.map({"${it.first.first} ${it.first.second} ${it.second}"}).joinToString("\n"))
    var sz = 2*(n+m+10)
    maxi = LongArray(8 * sz + 10){-INF}
    var ans:Long = 0
    //println(INF)
    for(pp in ps){
        var p = pp.first
        var v = pp.second.toLong()
        var x = p.first
        var y = p.second
        if (x>0)  v += getMax(1, 0, sz, 0, y+x)
        //println("ind ${x+y} v $v")
        ans = max(ans, v)
        modify(1, 0, sz, y+x, v)
    }
    println(ans)
    
    
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