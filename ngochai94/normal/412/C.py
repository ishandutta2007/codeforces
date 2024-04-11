x=raw_input()
lis=[]
for i in range(int(x)):
    t=raw_input()
    lis.append(t)
ans=''
for i in range(len(lis[0])):
    cur='a'
    fin=False
    for k in range(int(x)):
        if lis[k][i]!='?':
            if not fin:
                cur=lis[k][i]
                fin=True
            elif cur!=lis[k][i]:
                cur='?'
                break
    ans+=cur
print ans