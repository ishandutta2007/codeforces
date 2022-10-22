
import math
import sys

s=input()
l=len(s)
n=0

while n < 1000:

    n2=str(n)
    l2=len(n2)

    look=0
    yes=0
    for i in range(0,l):
        if n2[look]==s[i]:
            look+=1
        if look==l2:
            yes=1
            break
    if yes==1:
        ans=n
        break
    n+=8
if yes==1:
    print("YES")
    print(ans)
else:
    print("NO")