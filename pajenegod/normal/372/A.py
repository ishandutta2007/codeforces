import sys
import math
n=int(raw_input())
a=sorted(int(x) for x in sys.stdin)
i=(n//2)-1
j=n-1
k=0
while j>(n//2)-1 and i>=0:
    b = int(2*a[i]<=a[j])
    j-=1*b
    k+=1*b
    i-=1
#print(a)
print(n-k)