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
    var (n,m) = readInts()
    var a = Array(n, {i -> readInts()})
    var b = Array(n, {i -> Array(m, {j -> 0})})
    var poss = arrayListOf<Pair<Int, Int>>()
    for(i in 0..n-2) for(j in 0..m-2){
        var ok = true
        for (x in i..i+1) for (y in j..j+1) if(a[x][y]==0) ok = false;
        if (ok){
            poss.add(Pair(i+1,j+1))
            for (x in i..i+1) for (y in j..j+1) b[x][y] = 1
        }
    }
    var ok = true
    for(i in 0..n-1) for(j in 0..m-1) if(a[i][j]!=b[i][j]) ok = false
    if (ok){
        println(poss.size)
        for(p in poss){
            println("${p.first} ${p.second}")
        }
    }
    else println(-1)
    
    
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