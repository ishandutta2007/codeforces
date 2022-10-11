import sys
range = xrange
input = sys.stdin.readline

n = int(input())
A = [int(x) for x in input().split()]

good_gcd = [False]*(710**2)
for i in range(n):
    for j in range(n):
        a,b = A[i],A[j]
        while b:
            a,b = b,a%b
        good_gcd[i+710*j]=a>1
    good_gcd[i+710*n]=True
    good_gcd[n+710*i]=True


mem = [-1]*(2*710**2)

# [a,b)
def can_bst(left,a,b):
    #assert(a<b)
    val = a-1 if left==0 else b
    
    if b-a==0:
        return True
    elif b-a==1:
        return good_gcd[a*710+val]
    
    
    key = a+b*710+left*(710**2)
    if mem[key]==-1:
        for root_a in range(a,b):
            if good_gcd[710*root_a+val] and can_bst(1,a,root_a) and can_bst(0,root_a+1,b):
                mem[key]=True
                break    
        else:
            mem[key]=False
    return mem[key]


if can_bst(1,0,n):
    print 'Yes'
else:
    print 'No'