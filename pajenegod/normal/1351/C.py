import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    x,y = 0,0
    P = [(x,y)]
    for c in input():
        if c == 'N':
            y += 1
        elif c == 'S':
            y -= 1
        elif c == 'E':
            x += 1
        else:
            x -= 1
        P.append((x,y))
    seen = set()
    ans = 0
    for i in range(len(P) - 1):
        p1,p2 = sorted((P[i], P[i + 1]))
        if (p1,p2) in seen:
            ans += 1
        else:
            seen.add((p1,p2))
            ans += 5
    print ans