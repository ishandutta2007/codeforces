private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(){
	var n = readInt();
	var A = readInts();
	var B = mutableListOf(0);B.clear();
	A = A.reversed();var sz = 0;
	for(x in A){
		var t = B.indexOf(x);
		if(t != -1) continue;
		B.add(x);sz = sz+1;
	}
	B.reverse();
	println("$sz");
	for(x in B) print("$x ");
	// B = B.reverse();
}