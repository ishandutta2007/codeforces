# Not my code
# https://codeforces.com/contest/1404/submission/104915613

for _ in range(int(input())):
    n, k = map(int, input().split())
    s, l = input(), [""]*k
    for i in range(n):
        tmp = l[i%k]
        l[i%k] = None
        tmp += s[i]
        l[i%k] = tmp
    ans, c1, c2 = True, 0, 0
    for i in range(k):
        c1 += (1 if "1" in l[i] else -1)
        c2 += (-1 if "0" in l[i] else 1)
        ans &= not ("0" in l[i] and "1" in l[i])
    ans &= (c1 <= 0 and 0 <= c2)
    print("YES" if ans else "NO")