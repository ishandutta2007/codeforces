import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(x) - 1 for x in input().split()]
    
    count = 0.0

    for l in range(n):
        total = 0.0
        count0 = [0.0] * n
        count1 = [0.0] * n
        for i in range(l + 2, n):
            count1[A[i]] += 1

        for r in range(l + 2, n):
            a = A[r - 1]
            count0[a] += 1
            total += count1[a]
            
            a = A[r]
            count1[A[r]] -= 1
            total -= count0[a]
            
            if A[l] == A[r]:
                count += total
                #count += sum(count0[i] * count1[i] for i in range(n))

    print int(count)