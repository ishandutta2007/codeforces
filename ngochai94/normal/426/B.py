def test(lis):
    n=len(lis)
    if n%2==1:
        return False
    else:
        for i in range(n/2):
            if lis[i]!=lis[n-1-i]:
                return False
    return True
x=raw_input().split()
n=int(x[0])
lis=[]
for i in range(n):
    y=raw_input().split()
    lis.append(y[:])
while True:
    if not test(lis):
        break
    lis=lis[:len(lis)/2]
print len(lis)