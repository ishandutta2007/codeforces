import sys
range = xrange
input = raw_input

inter = lambda: int(input())
inters = lambda: [int(x) for x in input().split()]

def mapper(s):
    return [ord(c) - ord('a') for c in s]
def remapper(s):
    return ''.join(chr(c + ord('a')) for c in s)

def solve(n,m,A):
    for special in range(m):
        b = list(A[0])
        for car in range(26):
            b[special] = car
            
            for a in A:
                count = 0
                for i in range(m):
                    count += a[i] != b[i]
                if count > 1:
                    break
            else:
                return b
    return []
t = inter()
for _ in range(t):
    n,m = inters()
    A = [mapper(input()) for _ in range(n)]
    B = solve(n,m,A)
    if B:
        print remapper(B)
    else:
        print '-1'