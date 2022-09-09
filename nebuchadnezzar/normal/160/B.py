n = int(raw_input())
paper = list(map(int, raw_input()))
p1 = paper[0 : n]
p2 = paper[n : 2 * n]
p1.sort()
p2.sort()
prev = p1[0] - p2[0]
t = True
#print p1
#print p2
for i in xrange(n):
    if(prev * (p1[i] - p2[i]) <= 0):
        print "NO"
        t = False
        break
if(t == True):
    print "YES"