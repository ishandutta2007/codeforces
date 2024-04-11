import sys
range = xrange
input = raw_input

n = int(input())
for _ in range(n):
    S = [int(x) for x in input()]
    cumsum = [0]
    for s in S:
        cumsum.append(cumsum[-1] + s)
    
    count = 0
    for r in range(1, len(S) + 1):
        val = 0
        le = 1 
        while le < 20 and r - le >= 0:
            l = r - le
            val += S[l] << (le - 1)
            if val == le:
                count += 1
            le += 1
        pos_len = val
        if pos_len >= le and r - pos_len >= 0:
            l2 = r - le
            l1 = r - pos_len

            if cumsum[l2 + 1] - cumsum[l1] == 0:
                count += 1
    print count