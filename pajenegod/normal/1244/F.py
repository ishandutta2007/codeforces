import sys
range = xrange
input = raw_input

n, k = [int(x) for x in input().split()]
color = [0 if c == 'B' else 1 for c in input()]

locked = [0]*n

left = []
right = []

for i in range(n):
    im1 = i - 1 if i - 1 >= 0 else n - 1
    ip1 = i + 1  if i + 1 < n else 0

    if color[im1] == color[i] or color[i] == color[ip1]:
        locked[i] = 1

        if color[im1] != color[ip1]:
            if color[im1] == color[i]:
                right.append(i)
            else:
                left.append(i)
t = 0
while t < k and left:
    tmp = []
    for i in left:
        im1 = i - 1 if i - 1 >= 0 else n - 1
        if not locked[im1]:
            locked[im1] = 1
            color[im1] = color[i]
            tmp.append(im1)
    left = tmp
    
    tmp = []
    for i in right:
        ip1 = i + 1  if i + 1 < n else 0
        if not locked[ip1]:
            locked[ip1] = 1
            color[ip1] = color[i]
            tmp.append(ip1)
    right = tmp
    t += 1


print ''.join('BW'[(color[i] + (1 - locked[i]) *  t) & 1] for i in range(n))