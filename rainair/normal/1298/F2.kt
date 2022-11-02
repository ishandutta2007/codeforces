private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun max(a:Int,b:Int):Int{
	if(a > b) return a;
	return b;
}

val MAXN = 200000+5;
var tree = Array(2*MAXN,{i->0});

fun lowbit(x:Int):Int{
	return (x)and(-x);
}

fun add(ps:Int,d:Int):Unit{
	var pos = ps+MAXN;
	while(pos < 2*MAXN){
		tree[pos] = tree[pos]+d;
		pos = pos+lowbit(pos);
	}
}

fun query(ps:Int):Int{
	var pos = ps+MAXN;var res = 0;
	while(pos > 0){
		res = res+tree[pos];
		pos = pos-lowbit(pos);
	}
	return res;
}

fun min(a:Int,b:Int):Int{
	if(a > b) return b;
	return a;
}

var A = mutableListOf<Int>();
fun solve(n:Int,k:Int):Long{
	var B = mutableListOf<Int>(0);
	var ans:Long = 0;
	tree = Array(2*MAXN,{i->0});
	for(i in 1..n){
		if(A[i-1] < k) B.add(B[i-1]-1);
		else B.add(B[i-1]+1);
	}
	add(B[0],1);
	for(i in 1..n){
		ans = ans+query(B[i]-1);
		add(B[i],1);
	}
	return ans;
}

fun main(){
	var (n,k) = readInts();
	var rd = readInts();
	for(x in rd) A.add(x);
	println(solve(n,k)-solve(n,k+1));
}