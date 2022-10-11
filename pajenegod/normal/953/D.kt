fun main(arg: Array<String>){
    var s1: String
    var s2: String
    var s3: String
    var s4: String
    var s5: String
    var s6: String
    s1 = readLine()!!
    s2 = readLine()!!
    s3 = readLine()!!
    s4 = readLine()!!
    s5 = readLine()!!
    s6 = readLine()!!
    
    if (s1.substring(3,4)==".")
    {
        s1 = s1.substring(0,3)+"P"+s1.substring(4)
    } else if (s1.substring(4,5)==".")
    {
        s1 = s1.substring(0,4)+"P"+s1.substring(5)
    } else if (s2.substring(3,4)==".")
    {
        s2 = s2.substring(0,3)+"P"+s2.substring(4)
    } else if (s2.substring(4,5)==".")
    {
        s2 = s2.substring(0,4)+"P"+s2.substring(5)
    } else if (s1.substring(0,1)==".")
    {
        s1 = "P"+s1.substring(1)
    } else if (s1.substring(1,2)==".")
    {
        s1 = s1.substring(0,1)+"P"+s1.substring(2)
    } else if (s2.substring(0,1)==".")
    {
        s2 = "P"+s2.substring(1)
    } else if (s2.substring(1,2)==".")
    {
        s2 = s2.substring(0,1)+"P"+s2.substring(2)
    } else if (s1.substring(6,7)==".")
    {
        s1 = s1.substring(0,6)+"P"+s1.substring(7)
    } else if (s1.substring(7,8)==".")
    {
        s1 = s1.substring(0,7)+"P"
    } else if (s2.substring(6,7)==".")
    {
        s2 = s2.substring(0,6)+"P"+s2.substring(7)
    } else if (s2.substring(7,8)==".")
    {
        s2 = s2.substring(0,7)+"P"
    } else if (s3.substring(3,4)==".")
    {
        s3 = s3.substring(0,3)+"P"+s3.substring(4)
    } else if (s3.substring(4,5)==".")
    {
        s3 = s3.substring(0,4)+"P"+s3.substring(5)
    } else if (s4.substring(3,4)==".")
    {
        s4 = s4.substring(0,3)+"P"+s4.substring(4)
    } else if (s4.substring(4,5)==".")
    {
        s4 = s4.substring(0,4)+"P"+s4.substring(5)
    } else if (s5.substring(3,4)==".")
    {
        s5 = s5.substring(0,3)+"P"+s5.substring(4)
    } else if (s5.substring(4,5)==".")
    {
        s5 = s5.substring(0,4)+"P"+s5.substring(5)
    } else if (s6.substring(3,4)==".")
    {
        s6 = s6.substring(0,3)+"P"+s6.substring(4)
    } else if (s6.substring(4,5)==".")
    {
        s6 = s6.substring(0,4)+"P"+s6.substring(5)
    } else if (s3.substring(0,1)==".")
    {
        s3 = s3.substring(0,0)+"P"+s3.substring(1)
    } else if (s3.substring(1,2)==".")
    {
        s3 = s3.substring(0,1)+"P"+s3.substring(2)
    } else if (s4.substring(0,1)==".")
    {
        s4 = s4.substring(0,0)+"P"+s4.substring(1)
    } else if (s4.substring(1,2)==".")
    {
        s4 = s4.substring(0,1)+"P"+s4.substring(2)
    } else if (s3.substring(6,7)==".")
    {
        s3 = s3.substring(0,6)+"P"+s3.substring(7)
    } else if (s3.substring(7,8)==".")
    {
        s3 = s3.substring(0,7)+"P"+s3.substring(8)
    } else if (s4.substring(6,7)==".")
    {
        s4 = s4.substring(0,6)+"P"+s4.substring(7)
    } else if (s4.substring(7,8)==".")
    {
        s4 = s4.substring(0,7)+"P"+s4.substring(8)
    } else if (s5.substring(6,7)==".")
    {
        s5 = s5.substring(0,6)+"P"+s5.substring(7)
    } else if (s5.substring(7,8)==".")
    {
        s5 = s5.substring(0,7)+"P"+s5.substring(8)
    } else if (s6.substring(6,7)==".")
    {
        s6 = s6.substring(0,6)+"P"+s6.substring(7)
    } else if (s6.substring(7,8)==".")
    {
        s6 = s6.substring(0,7)+"P"+s6.substring(8)
    } else if (s5.substring(0,1)==".")
    {
        s5 = s5.substring(0,0)+"P"+s5.substring(1)
    } else if (s5.substring(1,2)==".")
    {
        s5 = s5.substring(0,1)+"P"+s5.substring(2)
    } else if (s6.substring(0,1)==".")
    {
        s6 = s6.substring(0,0)+"P"+s6.substring(1)
    } else if (s6.substring(1,2)==".")
    {
        s6 = s6.substring(0,1)+"P"+s6.substring(2)
    }
    
    
    println(s1)
    println(s2)
    println(s3)
    println(s4)
    println(s5)
    println(s6)
    
    
}