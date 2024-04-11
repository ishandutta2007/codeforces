import sys
range = xrange
input = raw_input

def solve(S):
    m = S.count('*')
    left = (m + 1)//2

    for i in range(len(S)):
        left -= S[i] == '*'
        if left == 0:
            break

    return sum(abs(i - j) for j in range(len(S)) if S[j] == '*')

t = int(input())
for _ in range(t):
    n = int(input())
    S = input()

    m = S.count('*')
    print solve(S) - solve('*' * m)