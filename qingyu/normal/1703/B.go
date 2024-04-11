package main

import (
	"fmt"
)

func main() {
	var str string
	var T int
	fmt.Scan(&T)
	for Case := 1; Case <= T; Case++ {
		var n int
		fmt.Scan(&n)
		fmt.Scan(&str)
		var table[256] int
		var ans int = 0
		for i := 0; i < n; i++ {
			id := int(str[i])
			if table[id] == 0 {
				ans += 2
			} else {
				ans += 1
			}
			table[id]++
		}
		fmt.Println(ans)
	}
}