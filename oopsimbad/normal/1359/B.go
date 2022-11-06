package main

import (
	"fmt"
	"bufio"
	"os"
)
var fin *bufio.Reader = bufio.NewReader(os.Stdin)
var fout *bufio.Writer = bufio.NewWriter(os.Stdout)
func max(a int, b int) int { if(a > b) { return a } else { return b }}
func main() {
	defer fout.Flush()
	var asdf int
	fmt.Fscan(fin, &asdf)
	for ; asdf > 0; asdf-- {
		var n,m,x,y int
		fmt.Fscan(fin, &n, &m, &x, &y)
		if 2*x < y {
			y = 2*x
		}
		ans := 0
		for ; n > 0; n-- {
			var s string
			fmt.Fscan(fin, &s)
			for i := 0; i < m; i++ {
				if s[i] == '*' {
					continue
				}
				if i != m-1 && s[i+1] == '.' {
					ans += y
					i++
				} else {
					ans += x
				}
			}
		}
		fmt.Fprintln(fout, ans)
	}
}