n,s=map(int,raw_input().split())
dic={}
for i in range(n):
    x,y,k=map(int,raw_input().split())
    z=x*x+y*y
    if z in dic:
        dic[z]+=k
    else:
        dic[z]=k
ans=False
for i in sorted(dic.keys()):
    s+=dic[i]
    if s>=10**6:
        ans=True
        print i**0.5
        break
if not ans:
    print -1