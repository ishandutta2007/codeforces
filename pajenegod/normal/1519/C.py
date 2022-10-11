# Not my code: https://codeforces.com/contest/1519/submission/114620914

def solve():
    n = int(input())
    u = list(map(int, input().split()))
    l = list(map(int, input().split()))
    d = {}
    for i in range(n):
        if u[i] in d:
            d[u[i]].append(l[i])
        else:
            e = [l[i]]
            d[u[i]] = e
 
    ans = [0]*n
    for ii in d:
        d[ii].sort(reverse = True)
        for i in range(1,len(d[ii])):
                d[ii][i] += d[ii][i-1]
        for k in range(1,len(d[ii])+1):
            new = ((len(d[ii])//k)*k)
            if new!=0:
                ans[k-1] += (d[ii][new-1])
 
 
    print(*ans)
 
 
for testis in range(int(input())):
    solve()