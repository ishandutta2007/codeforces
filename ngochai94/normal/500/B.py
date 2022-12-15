n=input()
lis=map(int,raw_input().split())
mat=[]
for i in range(n):
    mat.append(raw_input())
mark=[0]*n
gr=[]
for i in range(n):
    if mark[i]==0:
        cur=[i]
        que=[i]
        while que!=[]:
            con=que[0]
            que.pop(0)
            mark[con]=1
            for j in range(n):
                if mat[con][j]=='1' and mark[j]==0:
                    que.append(j)
                    cur.append(j)
                    mark[j]=1
        cur.sort()
        gr.append(cur)
for sm in gr:
    cur=[]
    for i in sm:
        cur.append(lis[i])
    cur.sort()
    for i in range(len(sm)):
        lis[sm[i]]=cur[i]
for i in lis:
    print i,