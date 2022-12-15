n,k,d=map(int,raw_input().split())
if k**d<n:
    print -1
else:
    ans=[]
    for i in range(n):
        cur=[]
        evaluate=i
        for j in range(d):
            cur.append(evaluate%k+1)
            evaluate/=k
        ans.append(cur)
    for i in range(d):
        for j in ans:
            print j[i],
        print '\n'