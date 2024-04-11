import java.io.PrintWriter

val pw = PrintWriter(System.out)
fun getOrd(c: Char): Int{
    "kotlin".forEachIndexed { index, ch ->  if(ch==c) return index}
    return -1
}
fun main(args: Array<String>) {
    var n = nextInt()
    var vs = MutableList(6){ MutableList(6){ mutableListOf<Int>()}}
    repeat(n){
        var s = next()
        vs[getOrd(s[0])][(getOrd(s.last())+1)%6].add(it)
    }
    var path = mutableListOf(0)
    var htap = mutableListOf<Int>()
    var cnt = MutableList(6){ MutableList(6){0}}
    repeat(6){i -> repeat(6){j -> cnt[i][j]=vs[i][j].size}}
    var sum= MutableList(6){0}
    repeat(6){i -> sum[i]=cnt[i].sum()}
    repeat(n){
        while(sum[path.last()]==0){
            htap.add(path.last())
            path.removeAt(path.lastIndex)
        }
        var i = cnt[path.last()].indexOfFirst {x -> x>0}
        cnt[path.last()][i]--
        sum[path.last()]--
        path.add(i)
    }
    htap.asReversed().forEach { x -> path.add(x) }
    var re = mutableListOf<Int>()
    repeat(n){i ->
        var v = path[i]
        var w = path[i+1]
        re.add(vs[v][w][cnt[v][w]++]+1)
    }
    println(re.joinToString(" "))
//    println(path)
    pw.flush()
}

fun next() = readLine()!!
fun nextInt() = next().toInt()
fun nextLong() = next().toLong()
fun nextDouble() = next().toDouble()
fun listOfString() = next().split(" ")
fun listOfInt() = listOfString().map { it.toInt() }
fun listOfLong() = listOfString().map { it.toLong() }
fun listOfDouble() = listOfString().map { it.toDouble() }