n=input()
s=map(int,raw_input().split())
t=max(s)
l=min(s)
if t!=l:
    print t-l,s.count(t)*s.count(l)
else:
    print 0,n*(n-1)/2