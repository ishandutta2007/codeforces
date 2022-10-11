import sys
range = xrange

b=w=0
switch = 0
S = raw_input()
S += S

prev = 'F'
count = 0
maxcount = 0
for c in S:
    if c!=prev:
        prev = c
        count += 1
    else:
        count = 1
    maxcount = max(maxcount,count)
print min(maxcount,len(S)//2)

#if len(S)==1:
#    print 1
#    sys.exit()
#
#prev = -1
#for c in S:
#    if c!=prev:
#        switch += 1
#        prev = c
#
#maxswitch = switch
#n = len(S)
#for i in range(n):
#    if S[i]!=S[(i+n-1)%n]:
#        switch += 1
#    if S[i]!=S[(i+1)%n]:
#        switch -= 1
#
#    maxswitch = max(maxswitch,switch)
#print maxswitch
#    
#
#
#