import sys
range = xrange
input = raw_input

rint = lambda: int(input())
rints = lambda: [int(x) for x in input().split()]

def ablock(i):
    if i == 4:
        return [2,0,3,1]
    elif i == 5:
        return [2,0,3,1,4]
    elif i == 6:
        return [2,0,4,1,3,5]
    else:
        return [2,0,4,1,5,3,6]

def bblock(i):
    if i == 4:
        return [1,3,0,2]
    elif i == 5:
        return [1,3,0,2,4]
    elif i == 6:
        return [1,4,0,3,5,2]
    else:
        return [1,4,0,3,5,2,6]

t = int(input())
for _ in range(t):
    n = rint()
    if n == 1:
        print 1
        continue
    if 1 < n < 4:
        print -1
        continue
    
    par = 1
    ans = []
    while n > 7:
        tmp = (ablock if par else bblock)(4)
        tmp = [len(ans) + 1 + x for x in tmp]
        ans += tmp
        par ^= 1
        n -= 4

    tmp = (ablock if par else bblock)(n)
    tmp = [len(ans) + 1 + x for x in tmp]
    ans += tmp
    par ^= 1
    
    print ' '.join(str(x) for x in ans)