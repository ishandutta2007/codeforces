import sys
range = xrange
input = raw_input

n = int(input())
s = [c for c in input()]
t = [c for c in input()]

A = []
B = []

for _ in range(n):
    for i in range(n):
        j = i
        while j+1<n and s[j]<s[j+1]:
            A.append(j)
            s[j],s[j+1] = s[j+1],s[j]
            j+=1
        j = i
        while j+1<n and t[j]<t[j+1]:
            B.append(j)
            t[j],t[j+1] = t[j+1],t[j]
            j+=1
if s==t:

    C = A+B[::-1]
    print len(C)
    print ' '.join(str(i+1) for i in C)
else:
    print -1