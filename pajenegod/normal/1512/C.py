import sys
range = xrange
input = raw_input

def mapper(c):
    if c == '0':
        return 0
    elif c == '1':
        return 1
    else:
        return -1

t = int(input())
for _ in range(t):
    a,b = [int(x) for x in input().split()]
    S = [mapper(c) for c in input()]

    n = a + b
    mid = n // 2
    if a & 1 and b & 1:
        print -1
        continue
    
    if a & 1 or b & 1:
        if S[mid] == -1:
            S[mid] = b & 1
        
        if S[mid] != b & 1:
            print -1
            continue

    for i in range(n):
        if S[i] != -1:
            if S[~i] != -1 and S[i] != S[~i]:
                print -1
                break
            S[~i] = S[i]
    else:
        for i in range(n):
            if S[i] == 0:
                a -= 1
            if S[i] == 1:
                b -= 1
        
        for i in range(n):
            if S[i] == -1:
                if a > 0:
                    S[i] = S[~i] = 0
                    a -= 2
                elif b > 0:
                    S[i] = S[~i] = 1
                    b -= 2

        if a == b == 0 and -1 not in S:
            print ''.join(str(c) for c in S)
        else:
            print -1