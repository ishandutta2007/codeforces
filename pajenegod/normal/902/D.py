from random import getrandbits as R

rb=lambda:R(1)

def modu(p,q):
    if len(q)==1:
        return [0]
    p=p[:]
    for d in range(len(p)-1,len(q)-2,-1):
        #print(d)
        a = p.pop()
        b = q[-1]
        B = [-k*a/b for k in q[:-1]]
        #print(B)
        for i in range(len(B)):
            p[i+1+len(p)-1-(len(q)-1)] += B[i]
    while len(p)>1 and abs(p[-1])<1E-6:
        p.pop()
    return p

def gcd(p,q):
    #print(p,q)
    if len(q)==1 and abs(q[0])<1E-6:
        return p,1
    #if len(q)<=1:
    #    return q,1
    else:
        p,iters = gcd(q,modu(p,q))
        return p,iters+1

#p,iters = gcd([5,3,2],[-10,1])

#print(p,iters)

#q,iters = gcd([2,5,4,1],[3,4,1])
#print(q,iters)

for n in [int(input())]:#range(150,0,-1):
    while True:
        p = [1]*(n+1)
        q = [1]*(n)

        for i in range(n):
            p[i]=rb()
        for i in range(n-1):
            q[i]=rb()

        Q,iters = gcd(p,q)
        if iters<n+1:
            continue
        #print(Q,iters)
        print(len(p)-1)
        print(*p)
        print(len(q)-1)
        print(*q)
        break