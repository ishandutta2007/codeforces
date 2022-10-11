from __future__ import division, print_function
py2 = round(0.5)

if py2:
    from future_builtins import ascii, filter, hex, map, oct, zip
    range = xrange

def go_deep(f):
    import sys
    r = 10**9
    sys.setrecursionlimit(r)    
    
    import threading
    threading.stack_size(2**27)
    a = threading.Thread(target=dum)
    a.start()
    a.join()

###################################

def readLine():
    a = input()
    return [int(i) for i in a.split()]

def deg(x, y):
    if y == 1:
        return x
    res = deg(x, y // 2)
    res *= res
    res %= md
    if y % 2 == 1:
        res *= x
        res %= md
    return res


nm = readLine()
n, m = nm[0], nm[1]
g = [[] for _ in range(n + 1)]
md = 1000000007

for i in range(n - 1):
    s = readLine()
    x, y, t = s[0], s[1], s[2]
    if t == 0:
        g[x].append(y)
        g[y].append(x)
ans = deg(n, m)
used = [False for _ in range (n + 1)]

def dum():
    global ans
    def dfs(v):
        used[v] = True
        c = 0
        for _, to in enumerate(g[v]):
            if used[to] == False:
                c += dfs(to)
        return c + 1
    
    for i in range(1, n + 1):
        if used[i] == False:
            b = dfs(i)
            ans = ans - deg(b, m)
            if ans < 0:
                ans += md

go_deep(dum)
print(ans)