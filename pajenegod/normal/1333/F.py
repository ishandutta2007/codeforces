import sys, collections
range = xrange
input = raw_input

n = int(input())

P = [1]*(n + 1)
smallest = [n + 2]*(n + 1)
smallest[1] = 1
for i in range(2, n + 1):
    if P[i]:
        smallest[i] = min(i, smallest[i])
        j = i * i
        while j <= n:
            P[j] = 0
            smallest[j] = min(i, smallest[j])
            j += i

adder = collections.defaultdict(int)
for i in range(1, n + 1):
    adder[i//smallest[i]] += 1

ind = 0
ans = [0]*(n + 1)
numbers = 0

for i in range(1, n + 1):
    numbers += adder[i]
    
    for j in range(ind, numbers + 1):
        ans[j] = i
    ind = numbers + 1

print ' '.join(str(x) for x in ans[2:])