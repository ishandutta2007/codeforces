x=raw_input().split()
n=int(x[0])
m=int(x[1])
min=int(x[2])
max=int(x[3])
y=raw_input().split()
lis=[]
for i in y:
    lis.append(int(i))
mi=100
ma=0
for i in lis:
    if i<mi:
        mi=i
    if i>ma:
        ma=i

ans=True
if min>mi or max<ma:
    ans=False
if n-m==1 and( min!=mi and max!=ma):
    ans=False
if n-m==0 and ( min!=mi or max!=ma):
    ans=False
if ans:
    print 'Correct'
else:
    print 'Incorrect'