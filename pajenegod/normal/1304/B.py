import sys
range = xrange
input = raw_input

n,m = [int(x) for x in input().split()]
S = []
for _ in range(n):
    S.append(input())

L = []
mid = []
R = []

pali = 0
taken = [0]*n
for i in range(n):
    if not taken[i]:
        for j in range(i + 1, n):
            if not taken[j] and S[i] == S[j][::-1]:
                taken[i] = 1
                taken[j] = 1
                L.append(S[i])
                R.append(S[j])
                break
        else:
            if not pali and S[i] == S[i][::-1]:
                pali = 1
                taken[i] = 1
                mid.append(S[i])
out = ''.join(L) + ''.join(mid) + ''.join(reversed(R))
print len(out)
print out