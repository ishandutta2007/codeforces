import sys
range = xrange
input = raw_input

n = int(input())
A = [int(x) for x in input().split()]

threes = []
for a in A:
    i = 0
    while a>0 and a%3==0:
        a//=3
        i+=1
    threes.append(i)

twos = []
for a in A:
    i = 0
    while a>0 and a%2==0:
        a//=2
        i+=1
    twos.append(i)
index = list(range(n))
index.sort(key = lambda i:(-threes[i],twos[i]))
print ' '.join([str(A[i]) for i in index])