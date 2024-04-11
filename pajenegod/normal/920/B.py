input = raw_input
range = xrange

q = int(input())
for _ in range(q):
    L = []
    R = []
    n = int(input())
    when = [[] for _ in range(5000)]
    for i in range(n):
        l,r = [int(x)-1 for x in input().split()]
        L.append(l)
        R.append(r)
        when[l].append(i)
    time = 0
    T = [0]*n
    for t in range(5000):
        A = when[t]
        A.sort()
        time = max(time,t)
        for stud in A:
            if R[stud]<time:
                continue
            T[stud]=time+1
            time+=1
    print " ".join([str(c) for c in T])