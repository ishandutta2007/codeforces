import kotlin.math.max
import kotlin.math.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs

fun main() {
    var n = readInt()
    var arr = readInts()
    var cnt = HashMap<Int, Int>()
    for (i in 0 until n) {
        cnt.put(arr[i], cnt.getOrDefault(arr[i], 0) + 1)
    }
    var last = 1
    while (cnt.getOrDefault(last, 0) == 2) {
        ++last
    }
    var l = 0
    var r = last
    var ans = CharArray(n)
    var real_ans = CharArray(n, {'B'})
    while (r - l > 1) {
        var mid = (l + r) / 2
//        System.err.println(mid)
        var part1 = ArrayList<Int>()
        var part2 = ArrayList<Int>()
        for (i in 0 until n) {
            var num = arr[i]
            if (num <= mid) {
                if (part1.size == part2.size) {
                    part1.add(num)
                    ans[i] = 'R'
                } else if (part1.size < part2.size) {
                    if (num == part2[part1.size]) {
                        part1.add(num)
                        ans[i] = 'R'
                    } else {
                        part2.add(num)
                        ans[i] = 'G'
                    }
                } else {
                    if (num == part1[part2.size]) {
                        part2.add(num)
                        ans[i] = 'G'
                    } else {
                        part1.add(num)
                        ans[i] = 'R'
                    }
                }
            } else {
                ans[i] = 'B'
            }
        }
        if (part1.size == part2.size) {
            l = mid
            for (i in 0 until n) {
                real_ans[i] = ans[i]
            }
        } else {
            r = mid
        }
    }

    println(real_ans.joinToString(separator = ""))
}