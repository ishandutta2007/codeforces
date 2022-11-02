#  

t = int(input())
for query in range(t):
    p = input()
    s = input()
    cnt = [0] * 26
    for c in p:
        cnt[ord(c) - ord('a')] += 1
    prefcnt = [[0] * 26 for i in range(len(s) + 1)]
    for i in range(len(s)):
        prefcnt[i + 1] = prefcnt[i].copy()
        prefcnt[i + 1][ord(s[i]) - ord('a')] += 1
    ans = False
    for i in range(len(s) - len(p) + 1):
        ok = True
        for j in range(26):
            ok = ok and (cnt[j] == (prefcnt[i + len(p)][j] - prefcnt[i][j]))
        if ok:
            ans = True
    if ans:
        print("YES")
    else:
        print("NO")