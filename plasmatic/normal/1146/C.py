from sys import stdout
for _ in range(int(input())):
    n = int(input())
    ans = 0
    
    for i in range(6, -1, -1):
        l = []
        r = []
        for j in range(1, n+1):
            if (j >> i) & 1:
                r.append(j)
            else:
                l.append(j)
        
        if l and r:
            print(len(l), len(r), *l, *r)
            stdout.flush()
            ans = max(ans, int(input()))
    
    print(-1, ans)
    stdout.flush()