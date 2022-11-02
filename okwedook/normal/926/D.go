package main

import (
    "fmt"
)

func main() {
    var ar [6]string
    var arr [6]string
    arr[0] = "33044033"
    arr[1] = "33044033"
    arr[2] = "22033022"
    arr[3] = "22033022"
    arr[4] = "11022011"
    arr[5] = "11022011"
    d := make([][]int, 0, 6);
    r := make([]int, 0, 6);
    var x int
    var y int
    var max int
    x = 0
    y = 0
    max = -1
    for i := 0; i < 6; i++ {
        var input string
        fmt.Scanln(&input)
        ar[i] = input
        // fmt.Println(input)
        for j := 0; j < 8; j++ {
            if input[j] == '-' || input[j] == '*' {
                r = append(r, 0)
            } else {
                ap := int(arr[i][j] - '0')
                r = append(r, ap)
                if ap > max {
                    max = ap
                    x = i
                    y = j
                }
            }
        }
        d = append(d, r)
    }
    s := ""
    
    for i := 0; i < 8; i++ {
        if i == y {
            s += "P"
        } else {
            s += string(ar[x][i])
        }
    }
    ar[x] = s
    for i := 0; i < 6; i++ {
        for j := 0; j < 8; j++ {
            fmt.Print(string(ar[i][j]))
        }
        fmt.Println()
    }
}