fun main(args: Array<String>) {
    val (a , x , y) = readLine()!!.split(' ').map(String::toInt)
    if((x > 0) and (x < a) and (y > 0) and (y < a))
        println(0)
    else if((x < 0) or (x > a) or (y < 0) or (y > a))
    	println(2)
    else
    	println(1)
}