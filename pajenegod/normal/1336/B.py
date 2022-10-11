import sys, itertools
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
for _ in range(t):
    nr = inp[ii]; ii += 1
    ng = inp[ii]; ii += 1
    nb = inp[ii]; ii += 1
    R = inp[ii: ii + nr]; ii += nr
    G = inp[ii: ii + ng]; ii += ng
    B = inp[ii: ii + nb]; ii += nb
    R.sort()
    G.sort()
    B.sort()

    ans = 2 * 10**18
    for A,B,C in itertools.permutations([R,G,B]):
        nA = len(A)
        nB = len(B)
        nC = len(C)
        
        iA = 0
        iB = 0
        iC = 0
        while iA < nA:
            while iB < nB and B[iB] < A[iA]:
                iB += 1
            if iB == nB:
                break
            a = A[iA]
            b = B[iB]
            
            mean = a + b
            while iC < nC and 2 * C[iC] < mean:
                iC += 1


            for x in iC - 1, iC:
                if 0 <= x < nC:
                    c = C[x]
                    ans = min(ans, (a-b)**2 + (a-c)**2 + (b-c)**2)
            iA += 1
    print ans