import java.io.PrintWriter

val pw = PrintWriter(System.out)
fun main(args: Array<String>) {
    val (n,m,q)=nlint()
    val mp= MutableList(n){nllong().toMutableList()}

    val rows=mp.map { vs -> vs.sum() }
    val cols= MutableList(m){0L}
    repeat(n){i -> repeat(m){j -> cols[j]+=mp[i][j]} }

    val r=Med(rows)
    val c=Med(cols)
    val re= mutableListOf<Long>(r.get()+c.get())
    repeat(q){
        var (y,x,v)=nlint()
        --y
        --x
        r.upd(y,v-mp[y][x])
        c.upd(x,v-mp[y][x])
        mp[y].set(x, v.toLong())
        re.add(r.get()+c.get())
    }
    println(re.joinToString(" "))

    pw.flush()
}

class Med(vs: List<Long>) {
    val vs:MutableList<Long> = vs as MutableList<Long>
    var sum=0L
    var psum=0L
    var i=0
    var cur=0L
    var pcur=0L
    init {
        sum=vs.sum()
        vs.forEachIndexed { i, v -> psum+=i*v }
        while(i<vs.size && (cur+vs[i])<=sum-(cur+vs[i])) {
            cur+=vs[i]
            pcur+=vs[i]*i
            ++i
        }
    }

    fun get(): Long {
        return i*cur-pcur + (psum-pcur)-i*(sum-cur)
    }
    fun upd(j: Int, ad: Long) {
        vs[j]+=ad
        sum+=ad
        psum+=ad*j
        if(j<i){
            cur+=ad
            pcur+=ad*j
        }
        while(i<vs.size && (cur+vs[i])<=sum-(cur+vs[i])) {
            cur+=vs[i]
            pcur+=vs[i]*i
            ++i
        }
        while(i>0 && cur>sum-cur){
            --i
            cur-=vs[i]
            pcur-=vs[i]*i
        }
    }
}

fun next() = readLine()!!
fun nint() = next().toInt()
fun nlong() = next().toLong()
fun ndouble() = next().toDouble()
fun nlstring() = next().split(" ")
fun nlint() = nlstring().map { it.toInt() }
fun nllong() = nlstring().map { it.toLong() }
fun nldouble() = nlstring().map { it.toDouble() }