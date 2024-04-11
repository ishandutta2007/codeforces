n,k=map(int,input().split())
counter=0
if n*2%k==0:
    counter+=n*2//k
else:
    counter+=n*2//k+1
if n*5%k==0:
    counter+=n*5//k
else:
    counter+=n*5//k+1
if n*8%k==0:
    counter+=n*8//k
else:
    counter+=n*8//k+1
print(counter)