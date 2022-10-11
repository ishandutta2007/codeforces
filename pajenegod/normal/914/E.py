import sys, os
range = xrange
input = raw_input
 
def centroid_decomp(coupl):
    n = len(coupl)
    
    bfs = [n - 1]
    for node in bfs:
        bfs += coupl[node]
        for nei in coupl[node]:
            coupl[nei].remove(node)
    
    size = [0] * n
    for node in reversed(bfs):
        size[node] = 1 + sum(size[child] for child in coupl[node])
 
    def centroid_reroot(root):
        N = size[root]
        while True:
            for child in coupl[root]:
                if size[child] > N // 2:
                    size[root] = N - size[child]
                    coupl[root].remove(child)
                    coupl[child].append(root)
                    root = child
                    break
            else:
                return root
        
    bfs = [n - 1]
    for node in bfs:
        centroid = centroid_reroot(node)
        bfs += coupl[centroid]
        yield centroid
 
inp = sys.stdin.read().split(); ii = 0
 
n = int(inp[ii]); ii += 1
coupl = [[] for _ in range(n)]
for _ in range(n - 1):
    u = int(inp[ii]) - 1; ii += 1
    v = int(inp[ii]) - 1; ii += 1
    
    coupl[u].append(v)
    coupl[v].append(u)
 
A = [1 << ord(c) - ord('a') for c in inp[ii]]; ii += 1
palistates = [0] + [1 << i for i in range(20)]
 
ans = [0.0] * n
dp = [0.0] * n
val = [0] * n
counter = [0] * (1 << 20)
 
for centroid in centroid_decomp(coupl):
    bfss = []
    for root in coupl[centroid]:
        bfs = [root]
        for node in bfs:
            bfs += coupl[node]
        bfss.append(bfs)
        
        for node in bfs:
            val[node] ^= A[node]
            for child in coupl[node]:
                val[child] = val[node]
    
    entire_bfs = [centroid]
    for bfs in bfss:
        entire_bfs += bfs
 
    for node in entire_bfs:
        val[node] ^= A[centroid]
        counter[val[node]] += 1
 
    for bfs in bfss:
        for node in bfs:
            counter[val[node]] -= 1
 
        for node in bfs:
            v = val[node] ^ A[centroid]
            for p in palistates:
                dp[node] += counter[v ^ p]
 
        for node in bfs:
            counter[val[node]] += 1
 
    for node in reversed(entire_bfs):
        dp[node] += sum(dp[child] for child in coupl[node])
 
    dp[centroid] += 1
    for p in palistates:
        dp[centroid] += counter[p]
    dp[centroid] //= 2
 
    for node in entire_bfs:
        ans[node] += dp[node]
        counter[val[node]] = val[node] = 0
        dp[node] = 0.0
    
print ' '.join(str(int(x)) for x in ans)