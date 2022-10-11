import sys
range = xrange
input = raw_input

n,k,l = [int(x) for x in input().split()]
S = [+(c<'a') for c in input()]

def solve2(cutoff, cumsum):
    DP = [0]*n
    count = [0]*n
    for i in range(n):
        end = i + l if i + l < n else n - 1
        inc = cumsum[end] - cumsum[i] - cutoff
        if inc > 0.0 and DP[end] < DP[i] + inc:
            DP[end] = DP[i] + inc
            count[end] = count[i] + 1
        if i + 1 < n and DP[i + 1] < DP[i]:
            DP[i + 1] = DP[i]
            count[i + 1] = count[i]
    return DP[-1], count[-1]

def solve(S):
    if k * l >= n:
        return 0
    
    cumsum = [0]
    for s in S:
        cumsum.append(cumsum[-1] + s)
    
    low = 0
    high = cumsum[-1] + 1
    while high - low > 1e-9:
        mid = low + high >> 1
        if solve2(mid, cumsum)[1] <= k:
            high = mid
        else:
            low = mid + 1

    val, count = solve2(high, cumsum)
    val += k * high
    #val += count * high
    #print val
    return cumsum[-1] - int(val + 0.5)

print min(solve(S), solve([1-x for x in S]))