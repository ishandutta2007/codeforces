import sys, os, __pypy__
range = xrange
input = raw_input
 
n, k = [int(x) for x in input().split()]
 
A = [+(c == 'R') for c in input()]
 
free = []
for i in range(n - 1):
    if A[i] and not A[i + 1]:
        free.append(i)
 
layers = []
while free:
    layer = []
    layers.append(layer)
    nextfree = []
    for i in reversed(free):
        layer.append(i + 1)
        A[i + 1] = 1
        A[i] = 0
        if i + 2 < n and not A[i + 2]:
            nextfree.append(i + 1)
        if i and A[i - 1]:
            nextfree.append(i - 1)
    free = nextfree
 
if k < len(layers):
    print -1
    sys.exit()
s = 0
for layer in layers:
    s += len(layer)
if k > s:
    print -1
    sys.exit()
 
out = __pypy__.builders.StringBuilder()
extra = k - len(layers)
for layer in layers:
    while len(layer) > 1 and extra:
        out.append("1 %d\n" % layer.pop())
        extra -= 1
    out.append(str(len(layer)))
    out.append(' ')
    
    for x in layer:
        out.append(str(x))
        out.append(' ')
    out.append('\n')
 
os.write(1, out.build())