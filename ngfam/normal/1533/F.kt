import kotlin.math.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs


fun main() {
    var s = readLn();
    val BUFFER = 700;

    var countOne = mutableListOf<Int>();
    var countZero = mutableListOf<Int>();

    var curOne = 0;
    var curZero = 0;

    for(c in s) {
        if (c == '1') {
            curOne += 1;
        }
        else {
            curZero += 1;
        }
        countOne.add(curOne);
        countZero.add(curZero);
    }

    var answers = mutableListOf<Int>();
    for(k in 1..s.length) {
        var nowStart = 0;
        var result = 0;
        var lastOne = 0;
        var lastZero = 0;

        while(nowStart < s.length) {
            result += 1;
            var low = nowStart;
            var high = s.length - 1;
            var ans = nowStart;

            while(low <= high) {
                var mid = (low + high) / 2;
                var one = countOne[mid] - lastOne;
                var zero = countZero[mid] - lastZero;

                if (one <= k || zero <= k) {
                    ans = mid;
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }

            lastOne = countOne[ans];
            lastZero = countZero[ans];
            nowStart = ans + 1;
        }
        answers.add(result);
    }

    println(answers.joinToString(" "));
}