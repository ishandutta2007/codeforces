object Main extends App {
	var i = 0
    var o = 0
    var e = 0
    var n = readLine().toLong
    val arr = readLine().split(" ").map(_.toLong)
    var k = 0
    
    while (i < n) {
        k = arr(i).toInt
        if (k % 2 == 1) {o += 1}
        else {e += 1}
        i += 1
    }
    if (o <= e) {print(o)}
    else {print(e + ((o-e) / 3))}
}