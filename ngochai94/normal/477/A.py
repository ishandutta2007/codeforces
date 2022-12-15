a,b=map(int,raw_input().split())
print (b*(b-1)/2*(a+a*b*(a+1)/2))%(10**9+7)