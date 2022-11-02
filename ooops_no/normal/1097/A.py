s=input()
l=list(map(str,input().split()))
x=False
for i in range(len(s)):
    for j in l:
        if j[i]==s[i]:
            print("YES")
            x=True
            break
    if x:
        break
if not(x):
    print("NO")