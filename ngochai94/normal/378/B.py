n=input()
lis1=[]
lis2=[]
for _ in range(n):
    a,b=map(int,raw_input().split())
    lis1.append(a)
    lis2.append(b)
ans1='1'*(n/2)
ans2='1'*(n/2)
for i in range(n/2,n):
    if lis1[i]<lis2[n-1-i]:
        ans1+='1'
    if lis2[i]<lis1[n-1-i]:
        ans2+='1'
print ans1+'0'*(n-len(ans1))
print ans2+'0'*(n-len(ans2))