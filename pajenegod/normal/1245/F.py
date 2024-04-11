import sys
range = xrange
input = raw_input

    

t = int(input())
for _ in range(t):
    a,b = [int(x) for x in input().split()]

    A = []
    B = []
    while a or b:
        A.append(a&1)
        B.append(b&1)
        a >>= 1
        b >>= 1

    memo = {}

    def solve(i, bound1, bound2):
        if i == -1:
            return 1
        key = (i, bound1, bound2)
        if key not in memo:
            a1 = 0 if bound1&1 else A[i]
            b1 = 1 if bound1&2 else B[i]
            
            a2 = 0 if bound2&1 else A[i]
            b2 = 1 if bound2&2 else B[i]

            count = 0
            for aa1 in range(2):
                if a1 <= aa1 <= b1:
                    for aa2 in range(2):
                        if a2 <= aa2 <= b2 and aa1&aa2!=1:
                            freel1 = bound1&1 or a1 < aa1
                            freer1 = bound1&2 or 2*(aa1 < b1)
                            
                            freel2 = bound2&1 or a2 < aa2
                            freer2 = bound2&2 or 2*(aa2 < b2)
                            count += solve(i - 1, freel1 + freer1, freel2 + freer2)
            memo[key] = count
        return memo[key]

    print solve(len(A) - 1, 0, 0)