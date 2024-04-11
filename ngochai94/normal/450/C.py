n,m,k=map(int,raw_input().split())
if k>n+m-2:
    print -1
else:
    print max((n*(m/(k+1))),(m*(n/(k+1))),(n/max(1,k-m+2)),(m/max(1,k-n+2)))