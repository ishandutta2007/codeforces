import java.io.*
import java.util.*
import kotlin.math.sign
import java.lang.Math.*
fun min(a:Int,b:Int):Int{if(a > b) return b;return a;}
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
	var n = readInt();
	var A = readIntArray(n);
	var mx = 0;
	var t1 = (-1e9).toInt();var p1 = -1;var t2 = (1e9).toInt();var p2 = -1;
	for(i in 0..n-1){
		if(A[i] > 0){
			mx = mx+A[i];
			if(A[i] < t2){
				t2 = A[i];
				p2 = i;
			}
		}
		if(A[i] < 0){
			if(A[i] > t1){
				t1 = A[i];
				p1 = i;
			}
		}
	}
	t1 = -t1;
	if(p1 == -1){
		println(mx-t2);
		for(i in 0..n-1){
			if(A[i] > 0 && i != p2) print("1");
			else print("0");
		}
		print("\n");return;
	}
	if(p2 == -1){
		println(mx-t1);
		for(i in 0..n-1){
			if(A[i] > 0 || i == p1) print("1");
			else print("0");
		}
		print("\n");return;
	}
	if(t1 < t2){
		println(mx-t1);
		for(i in 0..n-1){
			if(A[i] > 0 || i == p1) print("1");
			else print("0");
		}
		print("\n");return;
	}
	else{
		println(mx-t2);
		for(i in 0..n-1){
			if(A[i] > 0 && i != p2) print("1");
			else print("0");
		}
		print("\n");return;
	}
}

fun main(){
	var T = readInt();
	for(i in 1..T) Solve();
}