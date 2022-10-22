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
    var a = readInt()
    var b = readInt()
    var c = readInt()
    var d = readInt()
    var n1 = readInt()
    var n2 = n1
    var mini = 0
    var maxi = 0
    if (c < d){
        a = b.also { b = a }
        c = d.also { d = c }
    }
    
    var v = min(n2/d, b)
    maxi += v
    n2 -= v * d
    
    v = min(n2/c, a)
    maxi += v
    n2 -= v * c
    
    n1 -= a * (c-1) + b * (d-1)
    if (n1 > 0){
        mini = min(n1, a+b)
    }
    
    println("$mini $maxi")
    
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