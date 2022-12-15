n,k=map(int,raw_input().split())
print (6*n-1)*k
for i in range(n):
    print k*(6*i+1),k*(6*i+2),k*(6*i+3),k*(6*i+5)