package main

import (
	"fmt"
	"strings"
)

func main() {
	var str string
	var T int
	fmt.Scan(&T)
	for Case := 1; Case <= T; Case++ {
		fmt.Scan(&str)
		str = strings.ToLower(str)
		if str == "yes" {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}