lis=[]
for i in range(5):
    lis.append(map(int,raw_input().split()))
com=[]
for i in range(5):
    cur=[]
    for k in range(5):
        cur.append(lis[i][k]+lis[k][i])
    com.append(cur)
ans=0
from itertools import permutations
for i in permutations('01234'):
    i=map(int,i)
    ans=max(ans,com[i[0]][i[1]]+com[i[1]][i[2]]+2*(com[i[2]][i[3]]+com[i[3]][i[4]]))
print ans