import sys
range = xrange
input = raw_input

N = 1 << 9

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
m = inp[ii]; ii += 1

pizza_count = [0]*N
for i in range(n):
    f = inp[ii]; ii += 1
    pizza_mask = 0
    for _ in range(f):
        pizza_mask |= 1 << (inp[ii] - 1); ii += 1
    pizza_count[pizza_mask] += 1

mask_counter = [0]*N
for mask in range(N):
    x = 0
    
    i = mask
    while i:
        x += pizza_count[i]
        i = (i - 1) & mask
    mask_counter[mask] = x


inf = 10**9 + 10
best_price = [inf]*N
second_best_price = [inf]*N
count = [0]*N

prices = []
masks = []
for _ in range(m):
    p = inp[ii]; ii += 1
    prices.append(p)

    mask = 0
    f = inp[ii]; ii += 1
    for _ in range(f):
        mask |= 1 << (inp[ii] - 1); ii += 1

    masks.append(mask)
    
    count[mask] += 1
    if best_price[mask] > p:
        second_best_price[mask] = best_price[mask]
        best_price[mask] = p
    elif second_best_price[mask] > p:
        second_best_price[mask] = p


best = -1
bestval = 2 * inf
besti = -1
bestj = -1

for i in range(N):
    x = best_price[i]
    if x < inf:
        for j in range(N):
            y = best_price[j] if i!=j else second_best_price[j]
            if y < inf and (mask_counter[i | j] > best or (mask_counter[i | j] == best and x + y < bestval)):
                    best = mask_counter[i | j]
                    besti = i
                    bestj = j
                    bestval = x + y


x = best_price[besti]
for i in range(m):
    if masks[i] == besti and x == prices[i]:
        break

y = best_price[bestj] if besti != bestj else second_best_price[bestj]
for j in range(m):
    if i != j and masks[j] == bestj and y == prices[j]:
        break


print i + 1, j + 1