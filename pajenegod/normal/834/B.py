import os
from io import BytesIO


def main():
    input = BytesIO(os.read(0, os.fstat(0).st_size)).readline

    n, k = map(int, input().split())
    
    g = input()

    e = [-1] * 100
    for i,c in enumerate(g):
        e[c] = i
    
    curS = 0
    f = 1
    met = [0] * 100
    for i,c in enumerate(g):
        if not met[c]:
            curS += 1
            met[c] = 1
        if curS > k:
            print('YES')
            break
        if i == e[c]:
            curS -= 1
    else:
        print('NO')

main()