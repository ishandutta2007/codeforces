input = raw_input
range = xrange

q = int(input())

for _ in range(q):
    n,k = [int(x) for x in input().split()]
    X = [int(x)-1 for x in input().split()]
    wat = [False]*n
    uncov = n
    count = 0
    while uncov>0:
        Y = []
        for x in X:
            if x>=0 and x<n and not wat[x]:
                wat[x]=True
                uncov-=1
                Y.append(x-1)
                Y.append(x+1)
        X = Y
        count += 1
    print count