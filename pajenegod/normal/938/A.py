import sys
range = xrange
input = raw_input

vovel = 'aeiouyAEIOUY'

def has_double_v(s):
    n = len(s)
    for i in range(1,n):
        if s[i]in vovel and s[i-1] in vovel:
            return i
    return -1

n = int(input())
s = input()

while True:
    ind = has_double_v(s)
    if ind==-1:
        break
    #if ind<len(s)-1:
    s = s[:ind] + s[ind+1:]
    #else:
    #    s = s[:ind]
print s

#
#
#S = []
#for i in range(n-1,0,-1):
#    if s[i] in vovel and s[i-1] in vovel:
#        pass
#    else:
#        S.append(s[i])
#
#S.append(s[0])
#
#print ''.join(c for c in reversed(S))