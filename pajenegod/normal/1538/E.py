import sys
range = xrange
input = raw_input

def hahacount(S):
    count = 0
    for i in range(len(S) - 3):
        if S[i:i + 4] == 'haha':
            count += 1
    return count


inp = sys.stdin.read().split(); ii = 0

t = int(inp[ii]); ii += 1
for _ in range(t):
    n = int(inp[ii]); ii += 1
    variables = {}
    for _ in range(n):
        LHS = inp[ii]; ii += 1

        operation = inp[ii]; ii+= 1
        if operation == ':=':
            S = inp[ii]; ii += 1
            
            if len(S) >= 10:
                S2 = S[:3] + 'T' + S[-3:]
            else:
                S2 = S

            variables[LHS] = (hahacount(S), S2)
        else:
            a = inp[ii]; ii += 1
            ii += 1
            b = inp[ii]; ii += 1

            acount, astr = variables[a]
            bcount, bstr = variables[b]

            S = astr + bstr
            
            if len(S) >= 10:
                S2 = S[:3] + 'T' + S[-3:]
            else:
                S2 = S

            variables[LHS] = (acount + bcount + hahacount(S) - hahacount(astr) - hahacount(bstr), S2)

    print variables[LHS][0]