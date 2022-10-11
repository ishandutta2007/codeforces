n = int(raw_input())
a = [int(x)-1 for x in raw_input().split()]
inver = 0
#I = [0]*n
for i in xrange(n):
    for j in xrange(i+1,n):
        if a[j]<a[i]:
            inver = 1-inver
#            I[i]+=1

q = int(raw_input())
for _ in xrange(q):
    l,r = [int(x)-1 for x in raw_input().split()]
    inver += (r-l+1)//2
    inver%=2
#    for i in range((r-l)//2+1):
#        #print('swapping ',l+i,r-i)
#        #if a[r-i]<a[l+i]:
#        if a[r-i]!=a[l+i]:
#            inver=1-inver
#        a[l+i],a[r-i] = a[r-i],a[l+i]
    #print(a)
    if inver:
        print 'odd'
    else:
        print 'even'