package main

import (
	"fmt"
	"bufio"
	"os"
	"math"
)
var fin *bufio.Reader = bufio.NewReader(os.Stdin)
var fout *bufio.Writer = bufio.NewWriter(os.Stdout)
func max(a int, b int) int { if(a > b) { return a } else { return b }}
func main() {
	defer fout.Flush()
	var asdf int
	fmt.Fscan(fin, &asdf)
	for ; asdf > 0; asdf-- {
		var h, c, t float64
		fmt.Fscan(fin, &h, &c, &t)
		ans := 2
		m := (h+c)/2
		best := math.Abs(t-m)
		x := math.Floor((h-m)/(t-m))
		if int(x)%2 == 0 {
			x--;
		}
		if math.Abs(t-m-(h-m)/x) < best && x > 0 {
			best = math.Abs(t-m-(h-m)/x)
			ans = int(x)
		}
		x += 2
		if math.Abs(t-m-(h-m)/x) < best && x > 0 {
			best = math.Abs(t-m-(h-m)/x)
			ans = int(x)
		}
		fmt.Fprintln(fout, ans)
	}
}