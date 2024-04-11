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

var S : MutableList<MutableList<Int>> = ArrayList();
fun main(){
	var (n,m) = readInts();
	var A = readInts();
	var B = mutableListOf<Int>();
	for(x in A) B.add(x);
	B.sort();
	for(i in 1..n+1) S.add(mutableListOf<Int>());
	for(i in 1..m){
		var (x,y) = readInts();
		S[x].add(y);S[y].add(x);
	}
	// println(B);
	for(i in 1..n){
		var l = 0;var r = n-1;var ans = -1;
		while(l <= r){
			var mid = (l + r) shr 1;
			if(B[mid] >= A[i-1]) r = mid-1;
			else{
				ans = mid;
				l = mid+1;
			}
		}
		// println(ans);
		var out = max(0,ans+1);
		if(ans == -1) out = 0;
		for(x in S[i]) if(A[x-1] < A[i-1]) out = out-1;
		// println(S[i]);
		print("$out ");
	}
}