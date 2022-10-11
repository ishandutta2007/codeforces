import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    p,f = [int(x) for x in input().split()]
    cnts, cntw = [int(x) for x in input().split()]
    s,w = [int(x) for x in input().split()]

    if s < w:
        s,w = w,s
        cnts,cntw = cntw,cnts

    best = -1
    for swords in range(cnts + 1):
        count = swords
        left = p - s * swords
        lefts = cnts - swords
        leftw = cntw

        if left < 0:
            continue
        
        x = min(left//w, leftw)
        leftw -= x
        left -= w * x
        count += x

        left2 = f
        x = min(left2//w, leftw)
        leftw -= x
        left2 -= w * x
        count += x
        
        x = min(left2//s, lefts)
        lefts -= x
        left2 -= s * x
        count += x

        best = max(best, count)
    print best