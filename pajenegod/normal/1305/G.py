import sys
range = xrange
input = raw_input

n = int(input())
A = [int(x) for x in input().split()]

m = 2**18
count = [0]*m
for a in A:
    count[a] += 1
count[0] += 1

# Using dsu with O(1) lookup and O(log(n)) merge
owner = list(range(m))
sets = [[i] for i in range(m)]
 
total = 0
for profit in reversed(range(m)):
    a = profit
    b = a ^ profit
    while a > b:
        if count[a] and count[b] and owner[a] != owner[b]:
            total += (count[a] + count[b] - 1) * profit
            count[a] = 1
            count[b] = 1
            
            small = owner[a]
            big = owner[b]
            if len(sets[small]) > len(sets[big]):
                small, big = big, small
            for c in sets[small]:
                owner[c] = big
            sets[big] += sets[small]
        a = (a - 1) & profit
        b = a ^ profit
print total - sum(A)