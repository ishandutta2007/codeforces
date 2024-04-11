package main 

import "fmt"

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	var aa string
	fmt.Scan(&aa)
	var ok int
	ok = 0
	for i := 0; i+k-1 < n; i++{
	    var tmp int
	    tmp = 1
	    for j := i ; j < i + k; j++{
	        if aa[j] == 'Y'{
	            tmp = 0
	        }
	    }
	    var cur int
	    cur = k
	    for j := i+k ; j < n ; j++{
	        if aa[j] == 'N'{
	            cur += 1
	            if cur > k{
	               tmp = 0 
	            }
	        }else{
	            cur = 0
	        }
	    }
	    cur = k
	    for j := i-1 ; j >= 0 ; j--{
	        if aa[j] == 'N'{
	            cur += 1
	            if cur > k{
	                tmp = 0
	            }
	        }else{
	            cur = 0
	        }
	    }
	    if tmp == 1{
	        ok = 1
	    }
	}
	if ok == 1 {
			fmt.Printf("YES")
		} else {
			fmt.Printf("NO")
		}
}