def c(n,k):
    ans=1
    for i in range(k):
        ans*=n-i
    for i in range(k):
        ans/=i+1
    return ans
s1=raw_input()
s2=raw_input()
val=0
un=0
for i in s1:
    if i=='-':
        val-=1
    elif i=='+':
        val+=1
for i in s2:
    if i=='-':
        val+=1
    elif i=='+':
        val-=1
    else:
        un+=1
val=abs(val)
if val>un:
    print 0
else:
    print c(un,val+(un-val)/2)/float(2**un)