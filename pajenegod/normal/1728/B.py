import sys

t = int(input())
for _ in range(t):
    n = int(input())

    def solve(n):
        if n % 2 == 0:
            return list(range(1, n - 1)[::-1]) + [n - 1, n]
        else:
            A = solve(n - 1)
            A = [i + 1 for i in A]
            return [1] + A
        
    print(*solve(n))