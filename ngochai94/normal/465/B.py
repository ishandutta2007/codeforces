n=input()
s=map(int,raw_input().split())
out=1
ans=0
have=0
for i in s:
    if out==1:
        if i==1:
            have=1
            ans+=1
            out=0
    else:
        if i==1:
            ans+=1
            have=1
        else:
            ans+=1
            out=1
print ans-have+s[-1]