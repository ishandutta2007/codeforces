# NOT MY CODE: https://codeforces.com/contest/1204/submission/156891034
import sys
s=input()
dec_number= int(s, 2)
k=0
m=0
if dec_number==0 or dec_number==1:
    print(0)
    sys.exit()
    
while (dec_number + 4**k - 1)//4**(k) > 1:
    m+=1
    k+=1
print(m)