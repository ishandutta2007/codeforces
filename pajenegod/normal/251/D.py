import sys
range = xrange
input = raw_input
 
n = int(input())
A = [int(x) for x in input().split()]
 

# Reorder the bits
big = 60
mapper = [0]*big
ind = big - 1
xor = 0
for a in A: 
    xor ^= a
for j in reversed(range(big)):
    if xor & (1 << j) == 0:
        mapper[j] = ind
        ind -= 1
for j in reversed(range(big)):
    if xor & (1 << j):
        mapper[j] = ind
        ind -= 1

B = []
for a in A:
    tmp = 0
    for j in range(big):
        if a & (1 << j):
            tmp += 1 << mapper[j]
    B.append(tmp)
A = B

# returns I such that xor(A[i] for i in I) is maximized
def max_xor(A):
    who = []
    how = {}
    base = {}
     
    for i in range(len(A)):
        a = A[i]
        tmp = 0
        while a > 0:
            b = a.bit_length() - 1
            if b in how:
                a ^= base[b]
                tmp ^= how[b]
            else:
                base[b] = a
                how[b] = tmp | (1 << len(who))
                who.append(i)
                break
    x = 0
    tmp = 0
    for j in sorted(how, reverse = True):
        if not x & (1 << j):
            x ^= base[j]
            tmp ^= how[j]
    I = [who[j] for j in range(len(who)) if tmp & (1 << j)]
    return I

ans = [1]*n
for i in max_xor(A):
    ans[i] = 2
print ' '.join(str(x) for x in ans)