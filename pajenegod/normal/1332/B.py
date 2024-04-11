import sys,collections
range = xrange
input = raw_input

P = [2,3,5,7,11,13,17,19,23,29,31]

t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(x) for x in input().split()]

    C = []
    for a in A:
        i = 0
        while a % P[i]:
            i += 1
        C.append(i + 1)
    mapper = collections.defaultdict(lambda:len(mapper) + 1)
    C = [mapper[c] for c in C]
    print max(C)
    print ' '.join(str(x) for x in C)