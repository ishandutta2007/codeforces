import sys
range = xrange
input = raw_input
 
n,m,q = [int(x) for x in input().split()]
 
V = []
W = []
coupl = [[] for _ in range(n)]
for _ in range(m):
    a,b,w = [int(x) - 1 for x in input().split()]
    w += 1
    W.append(w)
 
    eind = len(V)
    V.append(b)
    V.append(a)
    coupl[a].append(eind)
    coupl[b].append(eind ^ 1)
 
DP = [[-1]*n for _ in range(n)]
DP[0][0] = 0
for j in range(1, n):
    prevDP = DP[j - 1]
    newDP = DP[j]
    for node in range(n):
        if prevDP[node] == -1:
            continue
        for eind in coupl[node]:
            nei = V[eind]
            newDP[nei] = max(newDP[nei], prevDP[node] + W[eind >> 1])
 
ans = 0
for dp in DP:
    ans += max(dp)
 
M = DP[-1]
K = []
for node in range(n):
    K.append(max(W[eind >> 1] for eind in coupl[node]))
 
K = [K[i] for i in range(n) if M[i] >= 0]
M = [M[i] for i in range(n) if M[i] >= 0]
 
 
def solve(K, M, a, b):
    hulli, hullx = convex_hull(K, M)
 
    def sqsum(n):
        return n * (n + 1) >> 1
    
    n = len(hulli)
    ans = 0
    # iterate over all n intervalls
    for i in range(n):
        j = hulli[i]
        k,m = K[j],M[j]
        l = max(a, hullx[i - 1] + 1 if i else a)
        r = min(b - 1, hullx[i] if i + 1 < n else b - 1)
 
        if l <= r:
            ans += m * (r - l + 1)
            ans += k * (sqsum(r) - sqsum(l - 1))
    return ans

def convex_hull(K, M, integer = True):
    """
    Given lines on the form y = K[i] * x + M[i] this function returns intervals,
    such that on each interval the convex hull is made up of a single line.
    Input:
        K: list of slope
        M: list of constant
        interger: boolean for turning on / off integer mode. Integer mode is exact, it
                  works by effectively flooring the seperators of the intervals.
    Return:
        hull_i: on interval j, line i = hull_i[j] is the largest
        hull_x: interval j and j + 1 is separated by hull_x[j], (hull_x[j] is the last x in interval j)
    """
    if integer:
        intersect = lambda i,j: (M[j] - M[i]) // (K[i] - K[j])
    else:
        intersect = lambda i,j: (M[j] - M[i]) / (K[i] - K[j])
    
    # assert len(K) == len(M)
    
    hull_i = []
    hull_x = []
    order = sorted(range(len(K)), key = K.__getitem__)
    for i in order:
        while True:
            if not hull_i:
                hull_i.append(i)
                break
            elif K[hull_i[-1]] == K[i]:
                if M[hull_i[-1]] >= M[i]:
                    break
                hull_i.pop()
                if hull_x: hull_x.pop()
            else:
                x = intersect(i, hull_i[-1])
                if hull_x and x <= hull_x[-1]:
                    hull_i.pop()
                    hull_x.pop()
                else:
                    hull_i.append(i)
                    hull_x.append(x)
                    break
    return hull_i, hull_x
 
ans += solve(K, M, 1, q - (n - 1) + 1)
 
print ans % (10 ** 9 + 7)