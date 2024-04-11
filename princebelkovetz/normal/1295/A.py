ans=[]
for _ in range(int(input())):
    b=int(input())
    if b%2==0:
        ans.append('1'*(b//2))
    else:
        ans.append('7'+'1'*((b//2)-1))
for i in range(len(ans)):
    print(ans[i])