import sys
range = xrange
input = raw_input

n = int(input())
A = [input() for _ in range(n)]
B = [input() for _ in range(n)]

A.sort()
B.sort()

tot = 0
while A and B:
    if A[-1]>B[-1]:
        tot+=1
        A.pop()
    elif A[-1]<B[-1]:
        tot+=1
        B.pop()
    else:
        A.pop()
        B.pop()
print (tot + len(A) + len(B))//2