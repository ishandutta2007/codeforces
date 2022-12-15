n,m,a,b=map(int,raw_input().split())
print min(n*a,(n/m)*b+(n%m)*a,b+(n-1)/m*b)