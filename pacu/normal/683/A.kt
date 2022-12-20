fun main(args: Array<String>){
    val (a, x, y) = readLine()!!.split(' ').map(String::toInt)
    if(x<0 || y<0 || x>a || y>a) println(2)
    else if(x==0 || y==0 || x==a || y==a) println(1)
    else println(0)
}