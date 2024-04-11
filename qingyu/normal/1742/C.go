package main

import (
	"fmt"
)


func main() {
	var T int
	fmt.Scan(&T)
	for Case := 1; Case <= T; Case++ {
		var G = [8]string{}
		for i := 0; i < 8; i++ {
			fmt.Scan(&G[i])
		}
		ans := -1
		for i := 0; i < 8; i++ {
			ok := true
			for j := 0; j < 8; j++ {
				if G[i][j] != 'R' {
					ok = false
				}
			}
			if ok {
				ans = 0
			}
		}
		for j := 0; j < 8; j++ {
			ok := true
			for i := 0; i < 8; i++ {
				if G[i][j] != 'B' {
					ok = false
				}
			}
			if ok {
				ans = 1
			}
		}
		if ans == 0 {
			fmt.Println("R")
		} else {
			fmt.Println("B")
		}
	}
}