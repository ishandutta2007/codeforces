M, K = map(int, raw_input().split())
dists = map(int, raw_input().split())
supply = map(int, raw_input().split())
max_supply = 0
tank = 0
total = 0

for i in xrange(M):
    tank += supply[i]
    max_supply = max(max_supply, supply[i])

    while tank < dists[i]:
        tank += max_supply
        total += K

    tank -= dists[i]
    total += dists[i]

print total