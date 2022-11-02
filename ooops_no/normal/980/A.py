x=input()
l=0
k=0
for i in x:
    if i=="-":
        l+=1
    else:
        k+=1
if k==1 or k==0:
    print("YES")
elif l%k==0:
    print("YES")
else:
    print("NO")