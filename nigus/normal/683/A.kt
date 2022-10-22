fun main(args: Array<String>) {
    val (s, x, y) = readLine()!!.split(' ').map(String::toInt)

    if (x <= s && x >= 0 && y <= s && y >= 0){

	if(x == 0 || x == s || y == 0 || y == s){
	val ans = 1;println(ans);
	}else{val ans = 0;println(ans);}
    }
    else{val ans = 2;println(ans);}
}