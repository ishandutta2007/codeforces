import sys
range = xrange
input = raw_input

n = int(input())
A = [int(x) for x in input().split()]

pairs = []
B = []
for a in A:
    if not B or abs(B[-1] - a) == 1:
        B.append(a)
    else:
        pairs.append((B[0], B[-1]))
        B = [a]
if B:
    pairs.append((B[0], B[-1]))

if len(pairs) < 7:
    pairs2 = []
    for a,b in pairs:
        pairs2.append((a,a))
        if abs(a - b) > 1:
            one = 1 if a < b else - 1
            pairs2.append((a + one,b - one))
        if a != b:
            pairs2.append((b,b))
    pairs = pairs2

def flip(pairs, l, r):
    P = []
    for a,b in pairs[l:r]:
        P.append((b,a))

    pairs = list(pairs)
    pairs[l:r] = reversed(P)
    return pairs
    
def ans(B, flips):
    global A
    global pairs
    if all(a<=b for a,b in B) and all(B[i][0] < B[i+1][0] for i in range(len(B) - 1)):
        out = []
        for l,r in flips:
            first = pairs[l][0]
            last = pairs[r - 1][1]
            pairs = flip(pairs, l, r)

            i = 0
            while A[i] != first:
                i += 1

            j = i
            while A[j] != last:
                j += 1
            
            A[i : j + 1] = A[i : j + 1][::-1]
            if i < j:
                out.append((i,j))
        assert(A == list(range(1, n + 1)))

        print len(out)
        for l,r in reversed(out):
            print l + 1, r + 1

        sys.exit()

def count(A):
    last = -2
    i = 0
    for a,b in A:
        i += abs(a - last) != 1
        last = b
    return i

m = len(pairs)
for l1 in range(m):
    for r1 in range(l1 + 1, m + 1):
        B1 = flip(pairs, l1, r1)
        if count(B1) <= 5:
            ans(B1, [(l1,r1)])

            for l2 in range(m):
                for r2 in range(l2 + 1, m + 1):
                    B2 = flip(B1, l2, r2)
                    if count(B2) <= 3:
                        ans(B2, [(l1,r1), (l2,r2)])

                        for l3 in range(m):
                            for r3 in range(l3 + 1, m + 1):
                                B3 = flip(B2, l3, r3)
                                if count(B3) == 1:
                                    ans(B3, [(l1,r1), (l2,r2), (l3,r3)])