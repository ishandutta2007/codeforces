import sys
range = xrange
input = raw_input

S = input()
n = len(S)
c = S[0]
if all(c==S[i] for i in range(n//2)) and all(c==S[i] for i in range((n+1)//2,n)):
    print 'Impossible'
    sys.exit()

for cut in range(1,n):
    s = S[cut:] + S[:cut]
    if s==s[::-1] and s!=S:
        print 1
        sys.exit()

print 2