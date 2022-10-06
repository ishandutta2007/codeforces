import java.io.PrintWriter

val pw = PrintWriter(System.out)
fun main(args: Array<String>) {
    val T = readi()
    repeat(T) {
        val (n, t) = readV()
        val s = reads()
        var rem = t
        var c0 = 0
        var c1 = 0
        var re = mutableListOf<Char>()
        for (c in s) {
            if (rem < 0) {
                re.add(c)
                continue
            }
            if (c == '1') {
                ++c1
            } else {
                if (rem < c1) {
                    repeat(c0) { re.add('0') }
                    repeat(c1 - rem.toInt()) { re.add('1') }
                    re.add('0')
                    repeat(rem.toInt()) { re.add('1') }
                    c0 = 0
                    c1 = 0
                    rem = -1
                } else {
                    rem -= c1
                    ++c0
                }
            }
        }
        print(MutableList(c0) { '0' }.joinToString(""))
        print(MutableList(c1) { '1' }.joinToString(""))
        println(re.joinToString(""))
    }
    pw.flush()
}

fun next() = readLine()!!
fun nint() = next().toInt()
fun nlong() = next().toLong()
fun ndouble() = next().toDouble()
fun nlstring() = next().split(" ")
fun nlint() = nlstring().map { it.toInt() }
fun nllong() = nlstring().map { it.toLong() }
fun nldouble() = nlstring().map { it.toDouble() }
fun reads() = next()
fun readi() = nint()
fun readl() = nlong()
fun readd() = ndouble()
fun readVs() = nlstring()
fun readVi() = nlint()
fun readVl() = nllong()
fun readVd() = nldouble()
fun read() = readl()
fun readV() = readVl()