import sys
import heapq
range = xrange
input = sys.stdin.readline

MOD = 10**9+7

n = int(input())

sellers = set()
sellheap = []
buyers = set()
buyheap = []
unknown = set()

addbook = set()
accbook = set()

ways = 1
for _ in range(n):
    d,p = input().split()
    p = int(p)
    
    
    if d=='ADD':
        #if p in addbook:
        #    print 0
        #    sys.exit()
        #addbook.add(p)
        if buyheap and p<=-buyheap[0]:
            buyers.add(p)
            heapq.heappush(buyheap,-p)
        elif sellheap and p>=sellheap[0]:
            sellers.add(p)
            heapq.heappush(sellheap,p)
        else:
            unknown.add(p)
    else: 
        #if p in accbook or p not in addbook:
        #    print 0
        #    sys.exit()
        #accbook.add(p)
        if p in unknown:
            # It is either sell or buy
            ways = ways*2%MOD
        elif not ((buyheap and p==-buyheap[0]) or (sellheap and p == sellheap[0])):
            # p is not best price
            print 0
            sys.exit()

        # Best price is now known to be p 
        for c in unknown:
            if c<p:
                buyers.add(c)
                heapq.heappush(buyheap,-c)
            elif c>p:
                sellers.add(c)
                heapq.heappush(sellheap,c)
        unknown.clear()

        sellers.discard(p)
        buyers.discard(p)
        if buyheap and p==-buyheap[0]:
            heapq.heappop(buyheap)   
        if sellheap and p == sellheap[0]:
            heapq.heappop(sellheap)
        if buyheap and sellheap and -buyheap[0]>=sellheap[0]:
            # shouldnt happen
            print 0
            sys.exit()

ways = ways*(len(unknown)+1)%MOD
print ways