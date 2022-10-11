import sys
range = xrange
input = raw_input

inp = sys.stdin.read().split(); ii = 0
out = []

t = int(inp[ii]); ii += 1
for _ in range(t):
    n = int(inp[ii]); ii += 1
    A = [ord(c) - ord('0') for c in inp[ii]]; ii += 1
    B = [ord(c) - ord('0') for c in inp[ii]]; ii += 1
    
    parA = A[0]
    O1 = []
    O2 = []
    for i in range(n):
        if A[i] != parA:
            O1.append(i)
            parA ^= 1
    parB = B[0]
    for i in range(n):
        if B[i] != parB:
            O2.append(i)
            parB ^= 1
   
    if parA != parB:
        O1.append(n)    

    O1 += reversed(O2)
    
    #for i in O1:
    #    flipper = A[:i]
    #    flipper = [1 - f for f in reversed(flipper)]
    #    A[:i] = flipper
    #print A
    #print B
    #assert A == B

    out.append(len(O1))
    out += O1
print '\n'.join(str(x) for x in out)