import sys
range = xrange
input = sys.stdin.readline

n,t = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]

X = [int(x) for x in input().split()]

if X[-1]!=n:
    print 'No'
    sys.exit()
#for i in range(n-1):
#    if not 0<=X[i+1]-X[i]<=1:
#        print 'No'
#        sys.exit()


best_time = 3*10**18
best_shit_time = best_time-1
B = []
shit_times = []
for i in reversed(range(1,n)):
    if X[i]!=n-len(B):
        print 'No'
        sys.exit()
    if X[i-1]==X[i]:
        if best_shit_time<A[i]+t:
            print 'No'
            sys.exit()
        shit_times.append(best_shit_time)
        best_shit_time-=1
    else:
        if best_time<A[i]+t:
            print 'No'
            sys.exit()
        B.append(best_time)
        for s in shit_times:
            B.append(s)
        shit_times = []
        best_time = min(A[i]+t-1,best_shit_time)
        best_shit_time = best_time-1

if X[0]!=n-len(B):
    print 'No'
    sys.exit()

B.append(best_time)
if best_time<A[0]+t:
    print 'No'
    sys.exit()

for s in shit_times:
    B.append(s)
shit_times = []

B = B[::-1]

big = 3*10**18
for i in range(n-1):
    if not 1<=B[i]<B[i+1]<=big:
        print 'No'
        sys.exit()

#C = list(B)
#for i in reversed(range(n)):
#    if C[-1]<A[i]+t or X[i]!=len(C):
#        print 'No'
#        sys.exit()
#    
#    b = len(C)-1
#    a = 0
#    while a!=b:
#        m = (a+b)//2
#        if C[m]>=A[i]+t:
#            b=m
#        else:
#            a=m+1
#

print 'Yes'
print ' '.join(str(x) for x in B)