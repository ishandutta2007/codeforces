import random

DEBUG = False
 
def ask_sqrt(x):
    if x in askd:
        return askd[x]
    print("sqrt",x)
    if DEBUG:
        roots = []
        for gg in range(1, n):
            if (gg*gg)%n == x:
                roots.append(gg)
        if len(roots) > 0:
            return roots[random.randrange(0, len(roots))]
        
        return -1
    else:
        res = int(input())
    return res
 
def superfactor():
    k = random.randrange(1, n)
    
    a = k%n
    a2 = (a*a)%n
    b2 = (1+2*a+a2+2*n)%n
    if b2 == 0:
        return superfactor()
    b = ask_sqrt(b2)
    askd[b2] = b
    if b == -1 or (a+b+1)%n == 0 or (a-b+1+n)%n == 0:
        return superfactor()
    
    return [(a+b+1)%n, (a-b+1+n)%n]
 
 
def gcd(i, j):
    if j == 0:
        return i
    return gcd(j,i%j)
 
n = int(input())
kk = 1
pairs = []

askd = {}

D = 20
 
for i in range(D):
    hej = superfactor()
    [x, y] = [hej[0], hej[1]]
    pairs.append([gcd(n,x), gcd(n,y)])
 

 
ans = []

while True:
    taken = -1
    #print(pairs)
    for i in range(len(pairs)):
        if pairs[i][0] != 1:
            taken = pairs[i][0]
            break
    if taken == -1:
        break
    for i in range(len(pairs)):
        g = gcd(taken, pairs[i][0])
        if g == 1:
            g = gcd(taken, pairs[i][1])
        if g != 1:
            taken = g
    
    if taken not in ans:
        ans.append(taken)
    for i in range(len(pairs)):
        if pairs[i][0]%taken == 0:
            pairs[i][0] //= taken
        if pairs[i][1]%taken == 0:
            pairs[i][1] //= taken
 
print("!",len(ans), *ans)