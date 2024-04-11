package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
)

func gcd(a, b int) int {
	if b != 0 {
		return gcd(b, a % b)
	}
	return a
}

func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var T int
	Fscan(in, &T)
	for Case := 1; Case <= T; Case++ {
		var n int
		Fscan(in, &n)
		var a = [1001]int{}
		for i := 0; i < n; i++ {
			var x int
			Fscan(in, &x)
			a[x] = i + 1
		}
		ans := -1
		for i := 0; i <= 1000; i++ {
			for j := 0; j <= i; j ++ {
				if gcd(i, j) == 1 && a[i] > 0 && a[j] > 0 {
					if ans < a[i] + a[j] {
						ans = a[i] + a[j]
					}
				}
			}
		}
		Fprintln(out, ans)
	}
}

func main() {
	run(os.Stdin, os.Stdout)
}