package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
)

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return a
}
func min(a, b int64) int64 {
	if a > b {
		return b
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
		var cnts, cntt = [26]int64{}, [26]int64{}
		cnts[0] = 1
		cntt[0] = 1
		for i := 0; i < n; i++ {
			var d, val int64
			var s string
			Fscan(in, &d, &val, &s)
			if d == 1 {
				for k := 0; k < len(s); k++ {
					cnts[s[k] - 'a'] += val
				}
			} else {
				for k := 0; k < len(s); k++ {
					cntt[s[k] - 'a'] += val
				}
			}
			var minsp, mintp, maxsp, maxtp int64 = 27, 27, -1, -1
			var k int64
			for k = 0; k < 26; k++ {
				if cnts[k] > 0 {
					minsp = min(k, minsp)
					maxsp = max(k, maxsp)
				}
				if cntt[k] > 0 {
					mintp = min(k, mintp)
					maxtp = max(k, maxtp)
				}
			}
			if minsp < maxtp {
				Fprintln(out, "YES")
				continue
			}
			if minsp > maxtp {
				Fprintln(out, "NO")
				continue
			}
			if cnts[minsp] < cntt[maxtp] && maxsp == minsp {
				Fprintln(out, "YES")
				continue
			}
			Fprintln(out, "NO")
		}
	}
}

func main() {
	run(os.Stdin, os.Stdout)
}