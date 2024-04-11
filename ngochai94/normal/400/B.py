can=True
x=raw_input().split()
n=int(x[0])
m=int(x[1])
lis=[]
for i in range(n):
    x=raw_input()
    g=x.index('G')
    s=x.index('S')
    if g>s:
        can=False
        break
    if s>g and s-g not in lis:
        lis.append(s-g)
if can:
    print len(lis)
else:
    print -1