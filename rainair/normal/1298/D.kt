private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun max(a:Int,b:Int):Int{
	if(a > b) return a;
	return b;
}

fun min(a:Int,b:Int):Int{
	if(a > b) return b;
	return a;
}

fun main(){
	var (n,w) = readInts();
	var A = readInts();
	var B = mutableListOf(A[0]);
	for(i in 1..n-1) B.add(B[i-1]+A[i]);
	var mx = (-1e9).toInt();var mn = (1e9).toInt();
	for(x in B){
		mx = max(mx,x);
		mn = min(mn,x);
	}
	var ans = max(0,min(w,w-mx)-max(0,-mn)+1);
	println("$ans");
}