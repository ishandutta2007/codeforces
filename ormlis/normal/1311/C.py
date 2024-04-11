from sys import stdin


def solve():
    n, m = map(int, input().split())
    s = input()
    ml = list(map(int, input().split()))
    ml.append(n)
    ml.sort(reverse=True)
    prev = 0
    ans = [0] * 26
    for i in range(m, -1, -1):
        for j in range(prev, ml[i]):
            ans[ord(s[j]) - ord('a')] += i + 1
        prev = ml[i]
    print(*ans)


for i in range(int(input())):
    solve()