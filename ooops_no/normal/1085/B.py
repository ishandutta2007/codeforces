n,k=map(int,input().split())
mns=99999999999999999
i=1
while i in range(1,k):
    mns1=n//i*k+i
    mns2=(mns1//k)*(mns1%k)
    if mns2==n:
        mns=min(mns,mns1)
    i+=1
print(mns)