import sys
range = xrange
input = raw_input
 
def main():
    MOD = 10**9+7
     
    inp = sys.stdin.read().split(); ii = 0
     
    n = int(inp[ii]); ii += 1
    X = [int(x) for x in inp[ii:ii + n]]; ii += n
     
    coupl = [[] for _ in range(n)]
    for _ in range(n - 1):
        a = int(inp[ii]) - 1; ii += 1
        b = int(inp[ii]) - 1; ii += 1
     
        coupl[a].append(b)
        coupl[b].append(a)
     
    P = [-1]*n
    Pval = [[] for _ in range(n)]
    Pkey = [[] for _ in range(n)]
     
     
    ans = 0
     
    bfs = [0]
    P[0] = 0
    for node in bfs:
        x = X[node]
     
        my_val = Pval[node]
        my_key = Pkey[node]
     
        p_val = Pval[P[node]]
        p_key = Pkey[P[node]]
     
        key = x
        for i in reversed(range(1, len(p_val))):
            old_key = p_key[i]
            val = p_val[i]
     
            while old_key:
                key, old_key = old_key, key % old_key
            
            if not my_key or my_key[-1] != key:
                my_key.append(key)
                my_val.append(val)
            else:
                my_val[-1] += val
            ans += (key % MOD) * val
        
        my_val.append(0)
        my_key.append(0)
        my_val.reverse()
        my_key.reverse()
     
        if x != 0:
            my_key.append(x)
            my_val.append(1 + p_val[0])
        else:
            my_val[0] += 1  + p_val[0]
     
        ans = (ans + x * (1 + p_val[0])) % MOD
        
        for nei in coupl[node]:
            if P[nei] == -1:
                P[nei] = node
                bfs.append(nei)
     
    print ans
main()