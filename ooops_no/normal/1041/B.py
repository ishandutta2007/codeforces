import math
a,b,c,d=map(int,input().split())
divisor=math.gcd(c,d)
c//=divisor
d//=divisor
print(min(a//c,b//d))