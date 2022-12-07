package main

import "fmt"

func main(){
    
    var t int
    var n int
    var k int
    
    fmt.Scanf("%d\n",&t)
    //fmt.Printf("%d\n", t);
    
    for i:=0 ; i<t ; i++ {
        fmt.Scanf("%d %d\n",&n,&k)
        //fmt.Printf("%d %d ",n,k)
        if n<=k {
            fmt.Printf("%d\n",k-n)
            continue
        }else{
            k = n-k
            fmt.Printf("%d\n",k%2)
        }
    }
}