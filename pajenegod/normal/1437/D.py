import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(x) for x in input().split()]

    intervals = []
    i = 1
    while i < n:
        j = i + 1
        while j < n and A[j - 1] < A[j]:
            j += 1
        intervals.append(j - i)
        i = j
    cur_layer = 1
    next_layer = 0
   
    layer_ind = 0
    layers = set()
    for count in intervals:
        next_layer += count
        cur_layer -= 1
        layers.add(layer_ind)

        if cur_layer == 0:
            layer_ind += 1
            cur_layer = next_layer
            next_layer = 0
    print len(layers)