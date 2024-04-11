import java.io.BufferedReader
import java.io.FileReader
import java.util.*
import kotlin.math.max

fun getVal(a : Array<Long>) : Long {
    var n = a.size - 1;
    var sum : Long = 0;
    var sumMul : Long = 0;
    for (i in 1..n) {
        sum += a[i];
        sumMul += i.toLong() * a[i];
    }
    var pos = 0;
    var tot : Long = 0;
    var totMul : Long = 0;
    for (i in 1..n) {
        tot += a[i];
        totMul += i.toLong() * a[i];
        if (tot * 2 >= sum) {
            pos = i;
            break;
        }
    }
//    println("${pos} ${tot} ${totMul}");
    var res : Long = 0;
    res += pos.toLong() * tot - totMul;
//    println("${sumMul - totMul} ${n - pos} ${sum - tot}")
    res += (sumMul - totMul) - pos.toLong() * (sum - tot);
//    println(res);

    return res;
}

fun main() {
    val sc = Scanner(System.`in`)
//    var tc = sc.nextInt()
    var tc = 1;
    for (t in 1..tc) {
        var n = sc.nextInt();
        var m = sc.nextInt();
        var q = sc.nextInt();
        var a = Array(n + 1){Array(m + 1){0} }
        var sumRow = Array<Long>(n + 1){0}
        var sumCol = Array<Long>(m + 1){0}
        for (i in 1..n) {
            for (j in 1..m) {
                a[i][j] = sc.nextInt();
                sumRow[i] += a[i][j].toLong();
                sumCol[j] += a[i][j].toLong();
            }
        }
//        for (i in 1..n) println(sumRow[i]);
        print("${getVal(sumRow) + getVal(sumCol)} ");
        for (qq in 1..q) {
            var x = sc.nextInt();
            var y = sc.nextInt();
            var z = sc.nextInt();
            var delta = z - a[x][y];
            sumRow[x] += delta.toLong();
            sumCol[y] += delta.toLong();
            a[x][y] = z;
            print("${getVal(sumRow) + getVal(sumCol)} ");
        }
        println()
    }
}