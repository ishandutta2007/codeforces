package main

import "fmt"
import "os"

func fail(){
	fmt.Println("NO")
	os.Exit(0)
}

func main(){
	var n int
	fmt.Scan(&n)
	var fi = false
	var l = -1
	var cur = 0
	var se = false
	var ans = 0
	for i := 0; i < n; i++ {
		var b int
		fmt.Scan(&b)
		if(!fi) {
			fi = true
			cur = 1
		}else{
			if(l == b) {
				cur += 1;
			}else{
				if(se) {
					if(ans != cur) { fail() }
				}else{
					se = true
					ans = cur
				}
				cur = 1
			}
		}
		l = b
	}
	if(se && ans != cur) { fail() }
	fmt.Println("YES")
}