import sys
range = xrange
input = raw_input


q = int(input())
for _ in range(q):
    n = int(input())
    S = [int(x) for x in input().split()]
    while S and 2048 not in S:
        S.sort(reverse=True)
        if len(S)>1 and S[-1] == S[-2]:
            S.append(S.pop() + S.pop())
        else:
            S.pop()
    if S:
        print 'YES'
    else:
        print 'NO'