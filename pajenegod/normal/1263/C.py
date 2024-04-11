import sys
range = xrange
input = raw_input

out = []
t = int(input())
for _ in range(t):
    n = int(input())
    
    found = [n]
    nsqrt = int(n**0.5 + 1)
    for i in range(2, nsqrt):
        x = n // i
        if found[-1] != x:
            found.append(x)

    y = n // nsqrt
    while y > 0:
        b = n//(y + 1) + 1
        x = n // b
        if found[-1] != x:
            found.append(x)
        y -= 1
    found.append(0)

    out.append(str(len(found)))
    out.append(' '.join(str(x) for x in reversed(found)))
print '\n'.join(out)