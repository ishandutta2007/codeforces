import sys
range = xrange
input = raw_input

inp = sys.stdin.read().split()
ii = 0

t = int(inp[ii])
ii += 1

out = []

for _ in range(t):
    S = [ord(c) - 48 for c in inp[ii]]
    ii += 1

    n = len(S)

    j = n - 1
    S[j] -= 1
    while j > 0 and S[j] == -1:
        S[j] = 9
        j -= 1
        S[j] -= 1

    if S[0] == 0:
        out.append('9'*(n - 2))
        continue

    if sum(1 for c in S if c==0) == n - 1:
        if S[0] == 1:
            out.append('9'*(n - 2))
        else:
            c = str(S[0] - 1)
            out.append(c + '9'*(n - 2) + c)
        continue
    
    nonzero = [0]
    for c in S:
        nonzero.append(nonzero[-1] + (c != 0))
    
    ans = []

    count = [0]*10
    match = True
    for i in range(n):
        c = S[i]
        
        left = n - i
        total = sum(count)
        if match:
            for j in reversed(range(c + 1)):
                totaltmp = total + 1 - 2*count[j]
                
                
                if i+1 > n - totaltmp:
                    continue
                
                count[j] ^= 1
                
                if j < c and n - i - 1 >= totaltmp:
                    break
                #if n - i - 1 >= totaltmp:
                #    break

                if i + 1 < n - totaltmp and nonzero[n - totaltmp] - nonzero[i + 1]:#any(S[i+1:-totaltmp]):
                    break
                
                k = -totaltmp
                ind = 0
                failed = False
                while k != 0:
                    while not count[ind]:
                        ind += 1
                    if S[k] < ind:
                        failed = True
                    elif S[k] > ind:
                        break

                    ind += 1
                    k += 1
                if not failed:break

                count[j] ^= 1
            else:
                assert(False)
            match = c == j
            ans.append(j)
        else:
            if total < left:
                count[9] ^= 1
                ans.append(9)
            else:  
                j = 9
                while not count[j]: j -= 1
                count[j] ^= 1
                ans.append(j)
    out.append(''.join(str(x) for x in ans))

print '\n'.join(out)