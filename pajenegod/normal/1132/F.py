import sys
n = int(input())
s = input().encode()

mem = [[-1]*(n+1) for _ in range(n+1)]

# Solve for s[l:r]
def DP(l,r):
    # Empty string
    if l==r:
        return 0
    if mem[l][r]==-1:
        # Either remove the left most character
        score = 1 + DP(l+1,r)
        
        # Or remove a piece in the middle
        for i in range(l+1,r):
            if s[l] == s[i]:
                # s[l+1:i] is the middle piece
                new_score = DP(l+1,i) + DP(i,r)
                score = min(score,new_score)
        mem[l][r] = score
    return mem[l][r]

print(DP(0,n))