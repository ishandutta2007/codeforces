import sys, heapq
range = xrange
input = raw_input

n = int(input())
A = [int(x) - i for i,x in enumerate(input().split())]

moves = 0
heap = []
for a in A:
    heapq.heappush(heap, -a)
    heapq.heappush(heap, -a)
    rem = -heapq.heappop(heap)
    moves += rem - a
print moves