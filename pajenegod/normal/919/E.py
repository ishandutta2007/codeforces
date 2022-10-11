a,b,p,x = [int(x) for x in input().split()]

ainv = pow(a,p-2,p)

count = 0

n = 1
exp = ainv*b%p
while n<p:
    m = n
    if exp>n:
        m += (n+p-exp)*(p-1)
    else:
        m += (n-exp)*(p-1)
    
    if m<=x: count += 1 + (x-m)//(p*(p-1))
    
    n += 1
    exp = (exp*ainv)%p

print(count)