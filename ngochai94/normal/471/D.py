n,w=map(int,raw_input().split())
bea=map(int,raw_input().split())
ele=map(int,raw_input().split())
s=[]
for i in range(1,w):
    s.append(ele[i]-ele[i-1])
s+=[10**10]
for i in range(1,n):
    s.append(bea[i]-bea[i-1])
t=len(s)
dic={i:0 for i in range(t+1)}
dic[0]=-1
j=-1
for i in range(1,t+1):
    while j!=-1 and s[i-1]!=s[j]:
        j=dic[j]
    j+=1
    dic[i]=j
ans=0
for i in range(w,t+1):
    if dic[i]==w-1:
        ans+=1
if w==1:
    print n
else:
    print ans