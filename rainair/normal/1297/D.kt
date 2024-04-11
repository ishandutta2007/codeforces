import java.io.*
import java.util.*
import kotlin.math.sign
import java.lang.Math.*
fun min(a:Int,b:Int):Int{if(a > b) return b;return a;}
fun min(a:Long,b:Long):Long{if(a > b) return b;return a;}
fun max(a:Int,b:Int):Int{if(a < b) return b;return a;}
fun min(a:Double,b:Double):Double{if(a > b) return b;return a;}
fun max(a:Double,b:Double):Double{if(a < b) return b;return a;}
fun qpow(aa:Long,nn:Long,ha:Long):Long{
	var res = 1.toLong();
	var a = aa;
	var n = nn;
	while(n != 0.toLong()){
		if((n and 1) == 1.toLong()) res = res*a%ha;
		a = a*a%ha;
		n = n shr 1;
	}
	return res;
}
@JvmField val INPUT = System.`in`
@JvmField val OUTPUT = System.out
@JvmField val cin = INPUT.bufferedReader()
fun readLine(): String? = cin.readLine()
fun readLn() = cin.readLine()!!
@JvmField var _tokenizer: StringTokenizer = StringTokenizer("")
fun read(): String {
    while (_tokenizer.hasMoreTokens().not()) _tokenizer = StringTokenizer(cin.readLine() ?: return "", " ")
    return _tokenizer.nextToken()
}
fun readInt() = read().toInt()
fun readDouble() = read().toDouble()
fun readLong() = read().toLong()
fun readStrings(n: Int) = List(n) { read() }
fun readLines(n: Int) = List(n) { readLn() }
fun readInts(n: Int) = List(n) { read().toInt() }
fun readIntArray(n: Int) = IntArray(n) { read().toInt() }
fun readDoubles(n: Int) = List(n) { read().toDouble() }
fun readDoubleArray(n: Int) = DoubleArray(n) { read().toDouble() }
fun readLongs(n: Int) = List(n) { read().toLong() }
fun readLongArray(n: Int) = LongArray(n) { read().toLong() }
@JvmField val cout = PrintWriter(OUTPUT, false)

fun Solve(){
	var (n,kk) = readInts(2);
	var k = kk.toLong();
	var A = readLongs(n);
	var S = mutableMapOf<Long,Int>();
	for(i in 0..n-1){
		S.put(A[i],i);
	}
	A = A.sorted();
	var tmp = 0.toLong();
	for(i in 0..n-2){
		tmp = tmp+A[n-1]-A[i]-(n-1-i);
	}
	var B = LongArray(n);
	if(tmp >= k){
		var i = n-2;
		while(i >= 0){
			B[S.getOrDefault(A[i],0)] = min(k,A[n-1]-A[i]-(n-1-i));
			k = k-min(k,A[n-1]-A[i]-(n-1-i));
			if(k == 0.toLong()) break;
			i = i-1;
		}
		B[S.getOrDefault(A[n-1],0)] = 0;
		for(x in B) print("$x ");print("\n");return;
	}
	var ps = n-2;
	while(ps >= 0){
		B[S.getOrDefault(A[ps],0)] = min(k,A[n-1]-A[ps]-(n-1-ps));
		k = k-min(k,A[n-1]-A[ps]-(n-1-ps));
		if(k == 0.toLong()) break;
		ps = ps-1;
	}
	for(i in 0..n-1){
		B[S.getOrDefault(A[i],0)] = B[S.getOrDefault(A[i],0)]+(k/n);
	}
	ps = n-1;
	k = k%n;
	while(k > 0){
		B[S.getOrDefault(A[ps],0)] = B[S.getOrDefault(A[ps],0)]+1.toLong();
		ps = ps-1;k = k-1;
	}
	for(i in 0..n-1) print("${B[i]} ");print("\n");
}

fun main(){
	var T = readInt();
	for(i in 1..T) Solve();
}