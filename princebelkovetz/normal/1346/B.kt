private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main(args:Array<String>) {
    var a = readInt()
    while (a != 0){
        var (n, k1, k2) = readInts()
        val s = readLn()
        var cou = 0
        var buf = 0
        if (k2 - k1 > k1){
            k2 = k1 * 2
        }
        for (i in 0..n - 1){
            if ((i == 0) and (s[i] == '0')) {
                continue
            }
            if ((i == 0) and (s[i] != '0')){
                cou += k1
                buf = k1
            } else if ((s[i] != '0') and (s[i - 1] == '0')){
                cou += k1
                buf = k1
            } else if (s[i] != '0'){
                buf = k2 - buf
                cou += buf
            }
        }
        println(cou)
        a--
    }

}