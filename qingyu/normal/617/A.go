package main

import "fmt"

const N int = 1e6 + 50
const inf int = 0x3f3f3f3f

var f[N] int

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func main() {
	var n int
	fmt.Scanf("%d", &n)
	for i := 0; i <= n; i++ {
		f[i] = inf
	}
	f[0] = 0
	for i := 1; i <= n; i++ {
		for j := 1; j <= 5; j++ {
			if j <= i {
				f[i] = min(f[i], f[i - j] + 1)
			}
		}
	}
	fmt.Println(f[n])
}