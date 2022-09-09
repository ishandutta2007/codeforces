private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    var n = readInt()
    var arr = readInts()
    var k = 0
    for (i in 0 until n) {
        if (arr[i] == -1) {
            k++
        }
    }
    var ans = Array<ArrayList<Int>>(k) {ArrayList<Int>()}
    var left = ArrayList<Int>()
    for (i in 0 until k) {
        left.add(i)
    }

    var finished = BooleanArray(k) {false}

    var next_left = ArrayList<Int>()
    var cnt = 0
    for (i in 0 until n) {
        var cur = left[cnt]
        if (arr[i] == -1) {
            finished[cur] = true
        } else {
            next_left.add(cur)
            ans[cur].add(arr[i])
        }
        cnt++
        if (cnt == left.size) {
            left.clear()
            left.addAll(next_left)
            next_left.clear()
            cnt = 0
        }
    }

    var outp = StringBuilder()
    outp.append(k)
    outp.append("\n")
    for (i in 0 until k) {
        outp.append(ans[i].size)
        outp.append(" ")
        for (num in ans[i]) {
            outp.append(num)
            outp.append(" ")
        }
        outp.append("\n")
    }
    print(outp.toString())
}