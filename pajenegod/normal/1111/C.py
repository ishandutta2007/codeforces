import sys
range = xrange
input = raw_input

n,k,A,B = [int(x) for x in input().split()]
pos = [int(x)-1 for x in input().split()]
pos.sort()


def f(l,r,i,j):
    while i<k and pos[i]<l:
        i+=1
    while j>=0 and pos[j]>=r:
        j -= 1

    counter = max(0,j-i+1)
    if counter == 0:return A
    if r-l == 1:
        return B*counter
    
    mid = (l+r)//2
    a = f(l,mid,i,j)
    b = f(mid,r,i,j)

    return min(B*counter*(r-l), a+b)

print f(0,2**n,0,k-1)