private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun max(a:Int,b:Int):Int{
	if(a > b) return a;
	return b;
}
var even = mutableMapOf<Int,Int>();
var odd = mutableMapOf<Int,Int>();
fun min(a:Int,b:Int):Int{
	if(a > b) return b;
	return a;
}

fun addeven(a:Int):Unit{
	if(even[a] == null){
		even.put(a,0);
	}
	var t = even.getOrDefault(a,0);
	even.put(a,t+1);
}

fun addodd(a:Int):Unit{
	if(odd[a] == null){
		odd.put(a,0);
	}
	var t = odd.getOrDefault(a,0);
	odd.put(a,t+1);
}

fun main(){
	var (n,p) = readInts();
	var A = readInts();
	var B = mutableListOf<Int>(0);
	var pos = mutableListOf<Int>();
	for(i in 1..n){
		if(A[i-1] < p) B.add(-1);
		if(A[i-1] > p) B.add(1);
		if(A[i-1] == p) {
			B.add(0);
			pos.add(i);
		}
	}
	for(i in 1..n) B[i] = B[i-1]+B[i];
	// add(0);
	addeven(0);
	var ans: Long = 0;
	for(i in 1..n){
		if(i%2 == 1){
			ans = ans+even.getOrDefault(B[i],0);
			ans = ans+odd.getOrDefault(B[i]-1,0);
			// println("$i : $ans");
			addodd(B[i]);
		}
		else{
			ans = ans+odd.getOrDefault(B[i],0);
			ans = ans+even.getOrDefault(B[i]-1,0);
			// println("$i : $ans");
			addeven(B[i]);
		}
		// add(B[i]);
	}
	var las = 0;
	pos.add(n+1);
	for(x in pos){
		var l = las+1;var r = x-1;
		odd.clear();even.clear();
		// S[B[las]].plus(1);
		if(las%2 == 1) addodd(B[las]);
		else addeven(B[las]);
		for(i in l..r){
			if(i%2 == 1){
				ans = ans-even.getOrDefault(B[i],0);
				ans = ans-odd.getOrDefault(B[i]-1,0);
				// println("$i : $ans");
				addodd(B[i]);
			}
			else{
				ans = ans-odd.getOrDefault(B[i],0);
				ans = ans-even.getOrDefault(B[i]-1,0);
				// println("$i : $ans");
				addeven(B[i]);
			}
		}
		las = x;
	}
	println(ans);
}