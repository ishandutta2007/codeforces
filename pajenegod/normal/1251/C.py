import sys
range = xrange
input = raw_input

ord0 = ord('0')

inp = sys.stdin.read().split(); ii = 0

t = int(inp[ii]); ii += 1
out = []
for _ in range(t):
    D = [ord(c) - ord0 for c in inp[ii]]; ii += 1

    odd = [d for d in D if d&1]
    even = [d for d in D if d&1 == 0]

    odd.reverse()
    even.reverse()

    ans = []
    while odd and even:
        if odd[-1] < even[-1]:
            ans.append(odd.pop())
        else:
            ans.append(even.pop())
    ans += reversed(odd)
    ans += reversed(even)

    out.append(''.join(str(x) for x in ans))

print '\n'.join(out)