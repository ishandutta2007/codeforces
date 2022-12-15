def border(s):
    dic={}
    j=-1
    dic[0]=-1
    for i in range(1,len(s)+1):
        while j!=-1 and s[i-1]!=s[j]:
            j=dic[j]
        j+=1
        dic[i]=j
    return dic
s=raw_input()
pre=border(s)
check={i:0 for i in range(-1,len(s))}
for i in pre:
    check[pre[i]]+=1
ans=pre[len(s)]
if check[ans]<2:
    ans=pre[ans]
    while ans!=0 and check[ans]==0:
        ans=pre[ans]
if ans<=0:
    print 'Just a legend'
else:
    print s[:ans]