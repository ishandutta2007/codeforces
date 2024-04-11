import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    t = [int(x) for x in input()]
    if all(c == t[0] for c in t):
        print ''.join(str(x) for x in t)
    else:
        ans = []
        for i in range(len(t)):
            ans.append(t[i])
            if i + 1 < len(t) and t[i] == t[i + 1]:
                ans.append(1 - t[i])
        print ''.join(str(x) for x in ans)