n,m=map(int,raw_input().split())
kmax=(n-m+1)*(n-m)/2
kmin=(n/m)*(n/m-1)/2*(m-n%m)+(n/m)*(n/m+1)/2*(n%m)
print kmin,kmax