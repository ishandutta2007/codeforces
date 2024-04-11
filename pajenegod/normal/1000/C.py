import sys
range = xrange
input = sys.stdin.readline

n = int(input())

eventsl = []
eventsr = []
inp = [int(x) for line in sys.stdin for x in line.split()]
for i in range(n):
    eventsl.append(inp[2*i])
    eventsr.append(inp[2*i+1]+1)

eventsl.sort()
eventsr.sort()

i = 0
j = 0
Arr = [0]*(n+1)
k = 0

last_event = None
while i<n and j<n:
    x = min(eventsl[i],eventsr[j])
    if last_event!=None:
        Arr[k]+=x-last_event
    last_event = x
    
    while i<n and x==eventsl[i]:
            k+=1
            i+=1
    while j<n and x==eventsr[j]:
            k-=1
            j+=1
while i<n:
    x = eventsl[i]
    if last_event!=None:
        Arr[k]+=x-last_event
    last_event = x
    
    while i<n and x==eventsl[i]:
            k+=1
            i+=1
while j<n:
    x = eventsr[j]
    if last_event!=None:
        Arr[k]+=x-last_event
    last_event = x
    
    while j<n and x==eventsr[j]:
            k-=1
            j+=1

print ' '.join(str(x) for x in Arr[1:n+1])