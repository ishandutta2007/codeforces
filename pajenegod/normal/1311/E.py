import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
    d = inp[ii]; ii += 1

    if d > n * (n - 1)//2:
        print 'NO'
        continue


    summa = 0
    layers = [[] for _ in range(n)]
    m = n
    bit = 0
    used = 0
    while m:
        dm = min(m, 1 << bit)
        summa += dm * bit
        m -= dm
        for _ in range(dm):
            layers[bit].append(used)
            used += 1
        bit += 1
    
    if d < summa:
        print 'NO'
        continue

    for maxused in reversed(range(len(layers))):
        if layers[maxused]:
            break
    layer = len(layers) - 1
    while True:
        while summa + maxused + 1 - layer <= d and len(layers[layer]) > 1:
            i = layers[layer].pop()
            summa += maxused + 1 - layer
            maxused += 1
            layers[maxused].append(i)

        if layer > 0 and len(layers[layer]) <= 1:
            layer -= 1
        else:
            break
    if summa != d:
        i = layers[layer].pop()
        layers[layer + d - summa].append(i)
    
    used = 0
    for layer in range(len(layers)):
        l = len(layers[layer])
        layers[layer] = list(range(used, used + l))
        used += l

    print 'YES'
    P = [-1]*n
    for layer in range(1, len(layers)):
        for i in range(len(layers[layer])):
            P[layers[layer][i]] = layers[layer - 1][i >> 1]
      
    
    score_calc = 0
    for layer in range(len(layers)):
        score_calc += len(layers[layer]) * layer
    assert d == score_calc

    print ' '.join(str(x + 1) for x in P[1:])