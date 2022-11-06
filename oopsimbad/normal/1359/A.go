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
		var n, m, k int
		fmt.Fscan(fin, &n, &m, &k)
		if m <= n/k {
			fmt.Fprintln(fout, m)
		} else {
			fmt.Fprintln(fout, n/k-(m-n/k+k-2)/(k-1))
		}
	}
}