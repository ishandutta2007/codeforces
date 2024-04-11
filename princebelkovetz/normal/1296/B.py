ans=[]
from math import floor
for _ in range(int(input())):
    n=input()
    cou=0
    while len(n)>1:
        cou += int(n[0])*10**(len(n)-1)
        n = int(n)-int(n[0])*10**(len(n)-1)+(floor(int(n[0])*10**(len(n)-1) / 10))
        n=str(n)
    cou+=floor(int(n[0]) / 10)+int(n[0])
    ans.append(cou)
for i in range(len(ans)):
    print(ans[i])