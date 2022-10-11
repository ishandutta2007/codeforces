import sys
range = xrange
input = raw_input

def bruter(C):
    found = [0] * len(C)
    count = 0
    while not all(found):
        count += 1
        A = []
        i = 0
        while found[i]:
            i += 1
        par = C[i]
        for i in range(len(C)):
            if not found[i] and par == C[i]:
                par ^= 1
                A.append(i)
        if len(A) & 1:
            A.pop()
        for i in A:
            found[i] = 1
    return count

n = int(input())
A = input()
B = input()

if sum(int(a) for a in A) != sum(int(b) for b in B):
    print -1
    sys.exit()

C = [int(A[i]) for i in range(n) if A[i] != B[i]]




prev = -1
AA = []
for c in C:
    if prev != c:
        AA.append(1)
        prev = c
    else:
        AA[-1] += 1

if len(AA) & 1:
    AA[0] += AA.pop()

count = 0
while AA:
    i = max(range(len(AA)), key = AA.__getitem__)
    AA = AA[i:] + AA[:i]
    
    count += 1
    m = len(AA)
    for i in range(m):
        AA[i] -= 1
    BB = []
    ii = 0
    while ii < m:
        if BB and BB[-1] == 0:
            BB.pop()
            if BB:
                BB[-1] += AA[ii]
            else:
                BB.append(AA[ii])
        else:
            BB.append(AA[ii])
        ii += 1
    if BB[-1] == 0:
        BB.pop()
        if len(BB) > 2:
            BB[0] += BB.pop()
    AA = BB


print count
#brute_ans = bruter(C)
#print count, brute_ans
#assert count == brute_ans