import sys
range = xrange
input = raw_input

n,k = [int(x) for x in input().split()]

mini = list(range(1,k+1))
score = sum(mini)

if score>n:
    print 'NO'
    sys.exit()

diff = (n - score)
add = diff//k
mini = [x + add for x in mini]
score += add*k

i = k-1
while score<n:    
    while i>0 and 2*mini[i-1]==mini[i]: i-=1
    if i == 0: break
    mini[i] += 1
    score += 1

if score == n:
    print 'YES'
    print ' '.join(str(x) for x in mini)
else:
    print 'NO'