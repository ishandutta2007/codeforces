from collections import deque, Counter, OrderedDict
from heapq import nsmallest, nlargest, heapify, heappop ,heappush, heapreplace
from math import ceil,floor,log,log2,sqrt,gcd,factorial,pow,pi
from bisect import bisect_left,bisect_right

# quick input
import io,os
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline


def binNumber(n,size=4):
    return bin(n)[2:].zfill(size)

def iar():
    return list(map(int,input().split()))

def ini():
    return int(input())

def isp():
    return map(int,input().split())

def sti():
    return str(input())

def par(a):
    print(' '.join(list(map(str,a))))

def tdl(outerListSize,innerListSize,defaultValue = 0):
    return [[defaultValue]*innerListSize for i in range(outerListSize)]

def sts(s):
    s = list(s)
    s.sort()
    return ''.join(s)

def bis(a, x):
    i = bisect_left(a, x) 
    if i != len(a) and a[i] == x: 
        return [i,True]
    else: 
        return [-1,False]

class pair:
    def __init__(self,f,s):
        self.fi = f
        self.se = s
    def __lt__(self,other):
        return (self.fi,self.se) < (other.fi,other.se)

#  =========     /\       /|    |====/|
#      |        /  \       |    |   / |
#      |       /____\      |    |  /  |
#      |      /      \     |    | /   |
#  ========= /        \  =====  |/====|  
#  code

if __name__ == "__main__":
    n,m = isp()
    a = iar()
    k = a[n-1]
    p = tdl(n+1,0)
    c = []
    for i in range(m):
        x,y = isp()
        p[x].append(y)
    for i in range(n+1):
        p[i].sort()
        c.append(Counter(p[i]))
    q = []
    i = n-1
    while i > 0:
        i -= 1
        if bis(p[a[i]] , k)[1]:
            sw = True
            for j in q:
                if c[a[i]][j] == 0:
                    sw = False
                    break
            if not sw:
                q.append(a[i])
        else:
            q.append(a[i])
        #print(a)
    print(n-1-len(q))