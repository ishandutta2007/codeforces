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
var A = IntArray(100000);

fun Solve(){
	var x = readInt();
	if(x <= 999){
		println(x);
		return;
	}
	if(x <= 999499){
		var flag = 0;if(x%1000 >= 500) flag = 1;
		println("${(x/1000)+flag}K");
		return;
	}
	if(x <= 1000000){
		println("1M");
		return;
	}
	var flag = 0;if(x%1000000 >= 500000) flag = 1;
	println("${(x/1000000)+flag}M");
}

fun main(){
	var T = readInt();
	for(i in 1..T) Solve();
}