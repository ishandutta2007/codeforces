x=raw_input()
num=[0,1,2,3,4,5,6,7,8,9]
spec=['.','_','@']
import string
let=string.ascii_lowercase
lis=x.split('.')
def bef(str):
    n=0
    for i in str:
        if not ( i in let):
            break
        n+=1
    return n
def aft(str):
    if not ('@' in str):
        return 0
    a=str.split('@')
    n=0
    if len(a[-1])==0:
        return 0
    for i in a[-1]:
        if i in spec:
            return 0
    for i in a[-2][::-1]:
        if i in let:
            n+=1
    return n
count=0    
for i in range(len(lis)-1):
    count+=aft(lis[i])*bef(lis[i+1])
print count