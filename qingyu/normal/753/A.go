package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	m := 1
	for (m + 1) * (m + 2) / 2 <= n {
		m++
	}
	fmt.Printf("%d\n", m)
	for i := 1; i < m; i++ {
		fmt.Printf("%d ", i)
		n -= i
	}
	fmt.Printf("%d\n", n)
}