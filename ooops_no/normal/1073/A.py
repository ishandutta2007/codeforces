x=int(input())
a=input()
l=[]
for i in a:
    if i not in l:
        l+=[i]
if len(l)>1:
    l=''
    l+=a[0]
    for i in a:
        if i in l:
            pass
        else:
            l+=i
            break
    print("YES")
    print(l)
else:
    print("NO")