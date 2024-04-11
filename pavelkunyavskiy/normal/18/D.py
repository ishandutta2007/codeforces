n=int(raw_input())
prev=[-1]*2500;
ans=[]
for i in range(0,n):
    (st,vls)=raw_input().split()
    vl=int(vls)
    if (st=='win'):
        prev[vl]=i
        if (i!=0):
            ans.append(ans[i-1])
        else:
            ans.append(0)
    else:
        tmp=0
        if (prev[vl]!=-1):
            tmp=2**vl
            if (prev[vl]!=0):
                tmp+=ans[prev[vl]]
        if (i!=0):
            tmp=max(tmp,ans[i-1])
        ans.append(tmp)
print ans[n-1]