num = int(raw_input())
mas = raw_input().split()

ans = -500000000

for i in xrange(1, num / 3 + 1):
    if(num % i == 0):
        for j in xrange(i):
            s = 0
            for k in xrange(j, num, i):
                s += int(mas[k])
            #print i, j
            ans = max(ans, s)    

print ans