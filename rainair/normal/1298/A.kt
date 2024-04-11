private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(){
	var A = readInts();
	for(i in 1..100000){
		A = A.shuffled();
		var c = A[3]-A[0];
		var a = A[1]-c;
		var b = A[2]-c;
		if(a > 0 && b > 0 && c > 0 && a+b == A[0] && a+c == A[1] && b+c == A[2] && a+b+c == A[3]){
			println("$a $b $c");
			return;
		}
	}
}