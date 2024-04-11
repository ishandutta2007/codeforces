import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    a,b,c = [int(x) for x in input().split()]

    m = 7 * ((a + b + c) // 9)
    if a + b + c == m // 7 * 9 and a >= m // 7 and b >= m // 7 and c >= m // 7:
        print('YES')
    else:
        print('NO')