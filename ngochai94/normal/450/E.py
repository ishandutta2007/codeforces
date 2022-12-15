n=input()
ans=[]
used={i:0 for i in range(1,n+1)}
an=0
for i in range(3,n/2+1,2)+[2]:
    prime=True
    for j in range(3,int(i**0.5)+1,2):
        if i%j==0:
            prime=False
            break
    if prime:
        cur=[i]
        l=1
        for j in range(3,n/i+1):
            if used[j*i]==0:
                cur.append(j*i)
                used[j*i]=1
                l+=1
        if l%2==1 and 2*i<=n:
            cur.append(2*i)
            used[2*i]=1
            l+=1
        for j in range(l/2):
            an+=1
            ans.append((cur[j*2],cur[2*j+1]))
print an
for i in ans:
    print i[0],i[1]