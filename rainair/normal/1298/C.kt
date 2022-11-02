private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun max(a:Int,b:Int):Int{
	if(a > b) return a;
	return b;
}

fun main(){
	var n = readInt();
	var str = readLn();
	var len = 0;
	var ans = 0;
	for(i in 0..n-1){
		if(str[i] != 'x'){
			ans = ans+max(0,len-2);
			len = 0;
		}
		else{
			len = len+1;
		}
	}
	ans = ans+max(0,len-2);
	println(ans);
}