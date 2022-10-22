
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
    var max:Int = 1 shl 14
    var half:Int = 1 shl 7
    println("? ${Array(100, {i->i}).joinToString(" ")}")
    var x1 = readInt()
    println("? ${Array(100, {i->(i+1) shl 7}).joinToString(" ")}")
    var x2 = readInt()
    var ans = ((x1 shr 7) shl 7) + (x2 and (half-1))
    println("! $ans")
    
    
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