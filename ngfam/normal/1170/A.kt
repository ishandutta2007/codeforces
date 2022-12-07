fun main(args: Array<String>) {
    var ntest = readLine()!!.toInt();
    while(ntest > 0) {
        ntest = ntest - 1;
        var (a, b) = readLine()!!.split(" ").map{ it.toInt() };
        a -= 1;
        b -= 1;
        var c = Math.min(a, b);
        println("${1 + a - c} ${c} ${1 + b - c}")
    }
}