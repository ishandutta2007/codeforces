n=input()
a=[]
b=[]
for i in range(n):
    c,d=map(int,raw_input().split())
    a.append(c)
    b.append(d)
exist=False
price=sorted(a)
quality=sorted(b)
p={}
q={}
for i in range(n):
    p[price[i]]=i
    q[quality[i]]=i
for i in range(n):
    if p[a[i]]!=q[b[i]]:
        exist=True
        break
if exist:
    print 'Happy Alex'
else:
    print 'Poor Alex'