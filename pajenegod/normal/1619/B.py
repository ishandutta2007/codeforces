import bisect

DP = []
upper = 10**9
i = 1
while i * i <= 10**9:
    DP.append(i * i)
    i += 1

i = 1
while i * i * i <= 10**9:
    DP.append(i * i * i)
    i += 1

DP = list(set(DP))
DP.sort()

t = int(input())
for _ in range(t):
    n = int(input())
    print(bisect.bisect_right(DP, n))