import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
q = inp[ii]; ii += 1

C = inp[ii: ii + n]; ii += n
C.append(0)
total = 0
for i in range(n):
    total += C[i] << i

inf = 10**18

ans = []
for _ in range(q):
    query = inp[ii]; ii += 1
    if query == 1:
        pos = inp[ii]; ii += 1
        val = inp[ii]; ii += 1

        total -= C[pos] << pos
        C[pos] = val
        total += C[pos] << pos

    else:
        x = inp[ii]; ii += 1
        k = inp[ii]; ii += 1

        if k > total:
            ans.append(-1)
            continue

        left = k
        makeable = 0
        for i in range(x + 1):
            left -= C[i]
            makeable += C[i] * ((1 << i) - 1)

        if left <= 0:
            ans.append(0)
            continue

        cost = 0
        for i in range(x + 1, n):
            c = C[i]

            count = min(left // (1 << i - x), c)
            cost += count * ((1 << i - x) - 1)

            c -= count
            extra = count << i - x
            left -= extra
            makeable += extra * ((1 << x) - 1)

            if c and left > 0:
                break
        else:
            ans.append(cost + left)
            continue


        I = i
        
        besta = inf
        if makeable >= left and besta > cost + left:
            besta = cost + left
        
        while left:
            make = left.bit_length() - 1

            cost += I - (x + make)
            I = x + make
            
            extra = 1 << I - x
            left -= extra
            makeable += extra * ((1 << x) - 1)
            cost += (1 << I - x) - 1

            if makeable >= left and besta > cost + left:
                besta = cost + left
        ans.append(besta)

print '\n'.join(str(x) for x in ans)