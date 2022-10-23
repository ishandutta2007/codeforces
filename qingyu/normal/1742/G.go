package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
)

func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var T int
	Fscan(in, &T)
	for Case := 1; Case <= T; Case++ {
		var n int
		Fscan(in, &n)
		var a, ok = []int{}, []int{}
		for i := 0; i < n; i++ {
			var x int
			Fscan(in, &x)
			a = append(a, x)
			ok = append(ok, 0)
		}
		var ans = []int{}
		now := 0
		for len(ans) < n {
			x, pos := 0, 0
			for i := 0; i < n; i++ {
				if ok[i] == 1 {
					continue
				}
				val := a[i] &^ now
				if val > x {
					x = val
					pos = i
				}
			}
			now |= x
			if x > 0 {
				ok[pos] = 1
				ans = append(ans, a[pos])
				continue
			}
			for i := 0; i < n; i++ {
				val := a[i] &^ now
				if val == x && ok[i] == 0 {
					ok[i] = 1
					ans = append(ans, a[i])
				}
			}
		}
		for i := 0; i < n; i++ {
			Fprintf(out, "%d ", ans[i])
		}
		Fprintf(out, "\n")
	}
}

func main() {
	run(os.Stdin, os.Stdout)
}