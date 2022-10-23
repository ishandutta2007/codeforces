package main

import (
	"fmt"
)


func main() {
	var T int
	fmt.Scan(&T)
	for Case := 1; Case <= T; Case++ {
		var a, b, c int
		fmt.Scan(&a, &b, &c)
		if a == b + c || b == a + c || c == a + b {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}