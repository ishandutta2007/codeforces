fun gcd(a: Int, b: Int): Int {
    if(b==0) return a
    else return gcd(b,a%b)
}

fun main(args: Array<String>) {
    var input: String = readLine()!!
    var np = 0
    var nplen = 0
    var npden = 1
    
    var i = 2
    while(input[i] != '(')
    {
        nplen++
        np = 10*np + (input[i]-'0')
        npden = 10*npden
        i++
    }
    
    var p = 0
    var plen = 0
    var pden = 1
    i++
    while(input[i] != ')')
    {
        plen++
        p = 10*p + (input[i]-'0')
        pden = 10*pden
        i++
    }
    pden--
    
    var num = np*pden + p
    var den = pden*npden
    var g = gcd(num,den)
    num /= g
    den /= g
    println("$num/$den")
}