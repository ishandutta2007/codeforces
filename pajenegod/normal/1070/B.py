import sys
range = xrange
input = raw_input

def reader(S):
    if '/' in S:
        S, base = S.split('/')
        base = int(base)
    else:
        base = 32
    a,b,c,d = [int(x) for x in S.split('.')]
    return ((1 << 32) + (a << 24) + (b << 16) + (c << 8) + d) >> (32 - base)

found = {}

n = int(input())
inp = sys.stdin.read().split()
for S in inp:
    if S[0] == '+':
        node = reader(S[1:])
        found[node] = -2
        node >>= 1
        while node and node not in found:
            found[node] = -1
            node >>= 1

ans = []

for S in inp:
    if S[0] == '-':
        node = reader(S[1:])
        if node in found and found[node] == -1:
            print -1
            sys.exit()

        check = node
        while check:
            if check in found and found[check] == -2:
                print -1
                sys.exit()
            check >>= 1

        prev = -1
        while node and node not in found:
            found[node] = 1
            prev = node
            node >>= 1
        if node and found[node] == 1:
            continue
        ans.append(prev)

if not ans:
    ans.append(1)

print len(ans)
out = []
mask = (1 << 8) - 1
for node in ans:
   base = node.bit_length() - 1
   
   node = (node ^ (1 << base)) << (32 - base)


   d = node & mask
   node >>= 8
   c = node & mask
   node >>= 8
   b = node & mask
   node >>= 8
   a = node & mask
   node >>= 8

   out.append('%d.%d.%d.%d/%d' % (a,b,c,d,base))
print '\n'.join(out)