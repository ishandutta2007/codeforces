import sys
import heapq

class PriorityQueue:
    def __init__(self, heap=[]): self.heap = heapq.heapify(heap) if heap else []
    def __bool__(self): return bool(self.heap)
    def __str__(self): return str(self.heap)
    def __len__(self): return len(self.heap)
    def push(self, x): heapq.heappush(self.heap, x)
    def top(self): return self.heap[0]
    def pop(self): return heapq.heappop(self.heap)
    def pushpop(self, x): return heapq.heappushpop(self.heap, x)

input = sys.stdin.readline

n, k = map(int, input().split())
lis = list(map(int, input().split()))
subamt = 0

pq = PriorityQueue()

i = 0
for ele in lis:
    pq.push((ele, i))
    i += 1

# Popping

while k > 0 and pq:
    v, idx = pq.pop()
    # print('k:', k, 'popped value:', v, 'subamt:', subamt)

    nv = v - subamt
    if nv > 0:
        print(nv)
        subamt += nv
        k -= 1

while k > 0: 
    print(0)
    k -= 1