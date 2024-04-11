n=input()
for i in range(n/2+1):
    k=i*2+1
    t=(n-k)/2
    print t*'*'+k*'D'+t*'*'
for i in range(n/2):
    t=n-2*(1+i)
    print (i+1)*'*'+'D'*t+'*'*(i+1)