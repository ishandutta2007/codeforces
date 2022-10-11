import sys
range = xrange
input = raw_input

mapper = {'R':0, 'P':1, 'S':2}

t = int(input())
for _ in range(t):
    S = [mapper[c] for c in input()]
    count = [0]*3
    for s in S:
        count[s] += 1
    maxi = max(range(3), key = count.__getitem__)
    maxi -= 2
    print ('RPS'[maxi]) * len(S)