n,d=map(int,raw_input().split())
s=map(int,raw_input().split())
t=d-((n-1)*10+sum(s))
if t<0:
    print -1
else:
    print t/5+(n-1)*2