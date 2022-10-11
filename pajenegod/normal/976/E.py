import sys
range = xrange
input = raw_input

n,a,b = [int(x) for x in input().split()]
inp = [int(x) for line in sys.stdin for x in line.split()]
order = list(range(n))

H = inp[::2]
D = inp[1::2]

if b==0:
    print sum(D)
    sys.exit()

order.sort(key=lambda i:D[i]-H[i])

H = [inp[2*i] for i in order]
D = [inp[2*i+1] for i in order]

eq = [False]*n

waiting_list = []

for i in range(n):
    if b>1 and H[i]>D[i]:
        b-=1
        eq[i]=True
        D[i]=H[i]
    elif H[i]>D[i]:
        waiting_list.append(i)

without = sum(D[i] for i in range(n))
best = without

for buff in range(n):
    # if already used a
    if eq[buff]:
        if len(waiting_list)==0:
            summa = without - D[buff] + (H[buff]<<a)
        else:
            new = waiting_list[0]
            summa = without - D[buff] + (H[buff]<<a) - D[new] + H[new]
    else:
        summa = without - D[buff] + max(D[buff],H[buff]<<a)
    best = max(best,summa)
print best