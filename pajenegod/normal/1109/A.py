import sys
range = xrange
input = raw_input

n = int(input())
A = [int(x) for x in input().split()]

cumA = [0]
for a in A:
    cumA.append(cumA[-1]^a)
odd = [0]*1050000
even = [0]*1050000
summa = 0
for i in range(n+1):
    if i%2==0:
        summa += even[cumA[i]]
        even[cumA[i]]+=1
    else:
        summa += odd[cumA[i]]
        odd[cumA[i]]+=1
print summa