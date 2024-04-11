import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
q = inp[ii]; ii += 1

count0 = 0
count1 = 0
count2 = 0

vec0 = [0]*n
vec1 = [0]*n

out = []
for _ in range(q):
    y = inp[ii] - 1; ii += 1
    x = inp[ii] - 1; ii += 1
    
    if y == 0:
        if vec0[x] == 0:
            vec0[x] = 1
            add = 1
        else:
            vec0[x] = 0
            add = -1
        
        if vec1[x]:
            count0 += add

        if x > 0 and vec1[x - 1]:
            count1 += add
        if x + 1 < n and vec1[x + 1]:
            count2 += add
    else:
        if vec1[x] == 0:
            vec1[x] = 1
            add = 1
        else:
            vec1[x] = 0
            add = -1
        
        if vec0[x]:
            count0 += add

        if x > 0 and vec0[x - 1]:
            count2 += add
        if x + 1 < n and vec0[x + 1]:
            count1 += add
    out.append(+(count0 == 0 and count1 == 0 and count2 == 0))
print '\n'.join('Yes' if x else 'No' for x in out)