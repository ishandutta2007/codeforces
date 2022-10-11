import sys
from collections import defaultdict

t = int(input())
for _ in range(t):
    n = int(input())

    counter = defaultdict(int)
    
    S1 = input().split()
    S2 = input().split()
    S3 = input().split()

    for S in S1, S2, S3:
        for s in S:
            counter[s] += 1
    
    out = []
    for S in S1, S2, S3:
        val = 0
        for s in S:
            if counter[s] == 1:
                val += 3
            elif counter[s] == 2:
                val += 1
        out.append(val)

    print(*out)