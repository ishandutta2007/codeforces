import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
out = []

def solve(n, A):
    same = [-1]*(2 * n)
    pos = [-1] * n
    for i in range(2 * n):
        a = A[i]
        if pos[a] == -1:
            pos[a] = i
        elif pos[a] == -2:
            return None
        else:
            p = pos[a]
            pos[a] = -2
            same[p] = i
            same[i] = p
    
    ans = []
    found = [0] * (2 * n)
    for root in range(2 * n):
        if found[root]:
            continue
        
        count0 = []
        count1 = []

        node = root
        while not found[node]:
            found[node] = 1
            found[same[node]] = 1
            
            if node & 1:
                count0.append(node >> 1)
            else:
                count1.append(node >> 1)
            
            node = same[node ^ 1]
        if len(count0) < len(count1):
            ans += count0
        else:
            ans += count1
    return ans

t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
    A = [x - 1 for x in inp[ii: ii + n]]; ii += n
    B = [x - 1 for x in inp[ii: ii + n]]; ii += n
    
    A = [A[i >> 1] if i & 1 == 0 else B[i >> 1] for i in range(2 * n)]

    ans = solve(n, A)
    if ans is None:
        out.append('-1')
    else:
        out.append(str(len(ans)))
        out.append(' '.join(str(x + 1) for x in ans))
print '\n'.join(out)