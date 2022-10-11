import sys
input = sys.stdin.readline

q = int(input())
Q = [input().split() for _ in range(q)]

last_seen = [-1] * 10**6
DP = [-1] * q
A = []

for t in reversed(range(q)):
    S = Q[t]
    if S[0] == '1':
        x = int(S[1])
        if last_seen[x] == -1:
            A.append(x)
        else:
            A.append(DP[last_seen[x]])
    else:
        x = int(S[1])
        y = int(S[2])
        if x == y:
            continue

        last_seen[x] = t
        if last_seen[y] == -1:
            DP[t] = y
        else:
            DP[t] = DP[last_seen[y]]

print(' '.join(str(x) for x in A[::-1]))