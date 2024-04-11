fun main(args: Array<String>) {
    var n = readLine()!!.toInt();
    var S = Array(n , {i -> "a"});
    var I = Array(n , {i -> "a"});
    var A = Array(n , {i -> "a"});
    

    for(i in 1..n){
        var (x,y) = readLine()!!.split(' ');
        S[i-1] = x;
        I[i-1] = (i-1).toString();
        A[i-1] = y;
    }
    
    for(i in 0..216){
        for(j in 0..(n-1)){
            
            var a = I[j].toInt();
            var b = A[a].toInt();
            
            if(b == i){
            println(S[a]);
            }
            
            
            
        }
    
    }
    

    
}