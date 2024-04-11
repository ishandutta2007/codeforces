import sys
range = xrange
input = sys.stdin.readline

n = int(input())
A = [n-int(x) for x in input().split()]

counter = [0]*(n+1)
for a in A:
    counter[a]+=1

for i in range(n+1):
    if counter[i]!=0:
        if counter[i]%i!=0:
            print 'Impossible'
            sys.exit()

unused = 1
counter = [0]*(n+1)
hatpick = [-1]*(n+1)

B = []
for a in A:
    if counter[a]==0:
        hatpick[a]=unused
        unused += 1
    B.append(hatpick[a])
    counter[a] = (counter[a]+1)%a
print 'Possible'
print ' '.join(str(x) for x in B)