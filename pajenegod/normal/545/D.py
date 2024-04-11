import sys
 
inp = [int(x) for x in sys.stdin.buffer.read().split()]; ii = 0
out = []
 
for t in range(1):
    n = inp[ii]; ii += 1
    A = inp[ii: ii + n]; ii += n
    A.sort()
    count=0
    prev=0
    while A:
        a = A.pop(0)
        if a>=prev:
            prev+=a
            count+=1
    out.append(count)
 
print('\n'.join(str(x) for x in out))