n, q = map(int, input().split())

servers = [0 for i in range(n)]

for i in range(q):
    t, k, d = map(int, input().split())
    
    cnt = 0
    for server in servers:
        if (server <= t): 
            cnt += 1
            if (cnt == k): break
        
    if (cnt >= k):
        s = 0
        for i in range(n):
            if (servers[i] <= t): 
                servers[i] = t + d
                cnt -= 1
                s += i+1
                if (cnt == 0): break
                
        print(s)
    else: print(-1)