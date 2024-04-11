import sys
range = xrange
input = raw_input

inf = -1

def mapper(S):
    return [ord(c) - ord('a') if c != '_' else -1 for c in S] 


inp = sys.stdin.read().split(); ii = 0

n = int(inp[ii]); ii += 1
m = int(inp[ii]); ii += 1
k = int(inp[ii]); ii += 1


P = []
for _ in range(n):
    P.append(mapper(inp[ii])); ii += 1

S = []
MT = []
for _ in range(m):
    S.append(mapper(inp[ii])); ii += 1
    MT.append(int(inp[ii]) - 1); ii += 1

for i in range(m):
    s = S[i]
    p = P[MT[i]]

    for ind in range(k):
        if s[ind] != p[ind] != -1:
            print 'NO'
            sys.exit()

coupl = [[] for _ in range(n)]
def solve(i, Sind, Pind):
    if i == k:
        Pset = set(Pind)
        MTset = {MT[ind] for ind in Sind}
        
        comb = Pset & MTset
        if len(comb) > 1:
            print 'NO'
            sys.exit()
        elif comb:
            x = comb.pop()
        else:
            x = Pind[0]
        
        for ind in Pind:
            if ind != x:
                coupl[x].append(ind)

        for ind in Sind:
            ind = MT[ind]
            if ind != x:
                coupl[ind].append(x)
    else:
        chatP = [[] for _ in range(27)]
        chatS = [[] for _ in range(27)]
        
        chatS[-1] = Sind
        for ind in Sind:
            chatS[S[ind][i]].append(ind)

        for ind in Pind:
            chatP[P[ind][i]].append(ind)

        for char in range(27):
            if chatS[char] and chatP[char]:
                solve(i + 1, chatS[char], chatP[char])

solve(0, list(range(m)), list(range(n)))

def find_SCC(coupl):
    SCC, S, P = [], [], []
    depth = [0] * len(coupl)
 
    stack = list(range(len(coupl)))
    while stack:
        node = stack.pop()
        if node < 0:
            d = depth[~node] - 1
            if P[-1] > d:
                SCC.append(S[d:])
                del S[d:], P[-1]
                for node in SCC[-1]:
                    depth[node] = -1
        elif depth[node] > 0:
            while P[-1] > depth[node]:
                P.pop()
        elif depth[node] == 0:
            S.append(node)
            P.append(len(S))
            depth[node] = len(S)
            stack.append(~node)
            stack += coupl[node]
    return SCC[::-1]

SCC = find_SCC(coupl)
if len(SCC) != n:
    print 'NO'
else:
    print 'YES'
    print ' '.join(str(A[0] + 1) for A in SCC)