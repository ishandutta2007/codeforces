import sys
range = xrange
input = raw_input

n = int(input())
s = input()
A = [0.0] + [float(x) for x in input().split()]

# Figure out optimal way to remove a group of i of the same characters 
DP = [0.0]*(n+1)
for i in range(1,n+1):
    DP[i] = max(A[i-j] + DP[j] for j in range(i))

mem = {} 
def score(S):
    n = len(S)
    if n==0:return 0.0

    if S not in mem:
        first_bit = S[0]
        i = 1
        while i<n and S[i]==first_bit: i+=1

        # Either remove those first i characters
        best = DP[i] + score(S[i:])
        
        for j in range(i,n):
            if S[j]==first_bit:
                # Or make that first part i+1 long by removing S[i:j]
                best = max(best, score(S[i:j]) + score(S[:i] + S[j:]))
        mem[S] = best
    return mem[S]

print int(score(s))