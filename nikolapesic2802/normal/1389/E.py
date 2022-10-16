from math import gcd
for _ in range(int(input())):
 m,d,w=map(int,input().split());m=min(m,d);d=w//gcd(w,d-1);w=m//d;print(w*m-w*(w+1)//2*d)