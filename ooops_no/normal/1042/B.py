x=int(input())
j={}
a=[]
for i in range(x):
    x=[str(i)for i in input().split()]
    if "A" in x[1] and "B" in x[1] and "C" in x[1]:
        x[1]="ABC"
    elif "B" in x[1] and "C" in x[1]:
        x[1]="BC"
    elif "B" in x[1] and "A" in x[1]:
        x[1]="AB"
    elif "A" in x[1] and "C" in x[1]:
        x[1]="AC"
    if x[1] not in a:
        a+=[x[1]]
        h=x[1],int(x[0])
        j.update([h])
    elif j[x[1]]>int(x[0]):
        j[x[1]]=int(x[0])
f=None
l=None
try:
    f=j["AB"]+j["AC"]
    if l==None or l>f:
        l=f
except Exception:
    pass
try:
    f=j["AB"]+j["BC"]
    if l==None or l>f:
        l=f
except Exception:
    pass
try:
    f=j["BC"]+j["AC"]
    if l==None or l>f:
        l=f
except Exception:
    pass
try:
    f=j["A"]+j["B"]+j["C"]
    if l==None or l>f:
        l=f
except Exception:
    pass
try:
    f=j["A"]+j["BC"]
    if l==None or f<l:
        l=f
except Exception:
    pass
try:
    f=j["ABC"]
    if l==None or f<l:
        l=f
except Exception:
    pass
try:
    f=j["AB"]+j["C"]
    if l==None or f<l:
        l=f
except Exception:
    pass
try:
    f=j["AC"]+j["B"]
    if l==None or f<l:
        l=f
except Exception:
    pass
if f==None:
    print(-1)
else:
    print(l)