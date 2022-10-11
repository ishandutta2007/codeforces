import sys
range = xrange
input = sys.stdin.readline

n,k = [int(x) for x in input().split()]

coupl = [[] for _ in range(n)]

inp = [int(x)-1 for line in sys.stdin for x in line.split()]
ii = 0

for _ in range(n-1):
    a,b = inp[ii],inp[ii+1]
    ii+=2
    coupl[a].append(b)
    coupl[b].append(a)

if not any(len(coupl[i])>=3 for i in range(n)):
    print 'No'
    sys.exit()

Q = []
found = [False]*n

for i in range(n):
    if len(coupl[i])==2:
        print 'No'
        sys.exit()
    
    if len(coupl[i])==1:
        Q.append(i)
        found[i] = True

count = len(Q)
counter = [0]*n

big_count = 0
times = 0
while count<n:
    times += 1
    big_count = count
    new_Q = []
    for node in Q:
        for nei in coupl[node]:
            if not found[nei]:
                
                if counter[nei]==0:
                    new_Q.append(nei)
                
                counter[nei] += 1
        
    for node in new_Q:
        if counter[node]<3 or (counter[node]!=len(coupl[node])-1 and big_count!=n-1) or (counter[node]!=len(coupl[node]) and big_count==n-1):
            print 'No'
            sys.exit()
        found[node] = True
    
    Q = new_Q
    if len(Q)==0:
        print 'No'
        sys.exit()
    count += len(Q)

if big_count==n-1 and times==k:
    print 'Yes'
else:
    print 'No'