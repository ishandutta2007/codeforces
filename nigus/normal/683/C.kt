fun main(args: Array<String>) {
    var A = readLine()!!.split(' ');
    var B = readLine()!!.split(' ');
    var F = Array(2001 , {i -> 0});
    
    var n1 = A[0].toInt();
    var n2 = B[0].toInt();
    
    for(i in 1..n1){
    
    var a = A[i].toInt()+1000;
    F[a] += 1;
    
    }
    
    for(i in 1..n2){
    
    var a = B[i].toInt()+1000;
    F[a] += 1;
    
    }
    
    var ans = 0;
    
    for(i in 0..2000){
        
        if(F[i] == 1){
        
        ans += 1;
        }
        
    }
    
    print(ans.toString() + " ")
    
    for(i in 0..2000){
        
        if(F[i] == 1){
        
        print((i-1000).toString() + " ")
        }
        
    }
    
}