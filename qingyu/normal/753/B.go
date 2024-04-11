package main

import (
	"fmt"
	"os"
	"time"
	"math/rand"
)
var candidates = []string{}
var array[10] int

func match(a string, b string, x int, y int) bool {
	cx := 0
	cy := 0
	var bucket[10] int
	for i := 0; i < 4; i++ {
		if a[i] == b[i] {
			cx++
		}
		bucket[a[i] - '0'] = 1
	}
	for i := 0; i < 4; i++ {
		if bucket[b[i] - '0'] == 1 {
			cy++
		}
	}
	return x == cx && y == cy - cx
}

func search_all(s string) {
	if (len(s) == 4) {
		candidates = append(candidates, s)
		return
	}
	for c := '0'; c <= '9'; c++ {
		t := c - '0'
		if array[t] == 0 {
			array[t] = 1
			search_all(s + string(c))
			array[t] = 0
		}
	}
}

func main() {
	rand.Seed(time.Now().UnixNano())
	search_all("")
	for {
		rand.Shuffle(len(candidates), func(i, j int) { candidates[i], candidates[j] = candidates[j], candidates[i] })
		fmt.Println(candidates[0])
		var a, b int
		fmt.Fscan(os.Stdin, &a, &b)
		if a == 4 {
			return
		}
		var new_candidates = []string{}
		for i := 1; i < len(candidates); i++ {
			if match(candidates[0], candidates[i], a, b) {
				new_candidates = append(new_candidates, candidates[i])
			}
		}
		candidates = new_candidates
	}
}