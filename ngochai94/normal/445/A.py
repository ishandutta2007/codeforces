n,m=map(int,raw_input().split())
ans=[]
for i in range(n):
    s=raw_input()
    cur=''
    for j in range(m):
        if s[j]=='-':
            cur+='-'
        elif (i+j)%2==0:
            cur+='W'
        else:
            cur+='B'
    ans.append(cur)
for i in ans:
    print i