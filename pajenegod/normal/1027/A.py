import sys
range = xrange
input = raw_input

q = int(input())
for _ in range(q):
    n = int(input())
    S = input()
    works = True
    for i in range(n//2):
        a = abs(ord(S[i])-ord(S[n-i-1]))
        if a==1 or a>2:works=False
    if works:
        print 'YES'
    else:
        print 'NO'