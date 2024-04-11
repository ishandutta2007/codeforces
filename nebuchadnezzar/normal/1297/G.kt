import java.util.*
import kotlin.collections.ArrayList
import kotlin.math.max
import kotlin.math.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs

fun main() {
    var (m, k) = readInts()
    k -= 1
    var tmp = m
    for (d in 2 until 10) {
        while (tmp % d == 0) {
            tmp /= d
        }
    }

    if (tmp != 1) {
        println(-1)
        return
    }

    if (m == 2 || m == 3 || m == 5 || m == 7) {
        var l = 1
        while (true) {
            if (k >= l) {
                k -= l
                l += 1
                continue
            }
            for (i in 0 until (l - 1 - k)) {
                print(1)
            }
            print(m)
            for (i in 0 until k) {
                print(1)
            }
            println()
            return
        }
    }

    var l = 1
    while (true) {
        var vars = TreeMap<Long, Long>()
        vars.put(1, 1)
        for (i in 0 until l) {
            var next = TreeMap<Long, Long>()
            for (v in vars) {
                for (d in 1 until 10) {
                    var cur = v.key * d
                    if (m % cur != 0.toLong()) {
                        continue
                    }
                    next.set(cur, min(next.getOrDefault(cur, 0) + v.value, 2e9.toLong()))
                }
            }
            vars = next
        }
        if (k >= vars.getOrDefault(m.toLong(), 0)) {
            k -= vars.getOrDefault(m.toLong(), 0).toInt()
            l += 1
            continue
        }
        var cur_prod = 1.toLong()
        for (pos in 0 until l) {
            for (d in 1 until 10) {
                if (m % (cur_prod * d) != 0.toLong()) {
                    continue
                }
                var vars = TreeMap<Long, Long>()
                vars.put(cur_prod * d, 1)
                for (i in pos + 1 until l) {
                    var next = TreeMap<Long, Long>()
                    for (v in vars) {
                        for (d in 1 until 10) {
                            var cur = v.key * d
                            if (m % cur != 0.toLong()) {
                                continue
                            }
                            next.set(cur, min(next.getOrDefault(cur, 0) + v.value, 2e9.toLong()))
                        }
                    }
                    vars = next
                }

                if (k >= vars.getOrDefault(m.toLong(), 0)) {
                    k -= vars.getOrDefault(m.toLong(), 0).toInt()
                    continue
                } else {
                    print(d)
                    cur_prod *= d
                    break
                }
            }
        }
        println()
        break
    }
}