package main

import (
	"fmt"
	"sort"
)


func main() {
	var T int
	fmt.Scan(&T)
	for Case := 1; Case <= T; Case++ {
		var n int
		fmt.Scan(&n)
		var a = []int{}
		for i := 0; i < n; i++ {
			var x int
			fmt.Scan(&x)
			a = append(a, x)
		}
		sort.Ints(a)
		ok := true
		for i := 0; i + 1 < n; i++ {
			if a[i] == a[i + 1] {
				ok = false
				break
			}
		}
		if ok {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}