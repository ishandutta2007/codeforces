import sys
range = xrange
input = raw_input

def solve(n,H):
    hdiff = min(H[i + 1] - H[i] for i in range(n - 1))
    if H[1] - H[0] == hdiff:
        return H[0]
    if H[-1] - H[-2] == hdiff:
        return H[-2]
    for i in range(n - 1):
        if H[i + 1] - H[i] == hdiff:
            return H[i]

t = int(input())
for _ in range(t):
    n = int(input())
    H = [int(x) for x in input().split()]
    H.sort()

    i = H.index(solve(n, H))
    
    h1 = H.pop(i)
    h2 = H.pop(i)

    H1 = [h for h in H if h < h1]
    H2 = [h for h in H if h >= h1]

    H = [h1] + H2 + H1 + [h2]

    print ' '.join(str(x) for x in H)