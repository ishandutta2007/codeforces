big = int(2e5)
n = int(input())
a = list(map(int, input().split()))

facts = [[] for _ in range(big + 1)]
for div in range(2, big + 1):
    if len(facts[div]) == 0:
        for i in range(1, big//div + 1):
            num = i*div
            count = 0
            while num % div == 0:
                num //= div
                count += 1
            facts[div*i].append((div, count))

#print(facts[:20])
# If a factor appears in all but 1 number it lives
mins = {}
for ai in a:
    for div, count in facts[ai]:
        if div in mins:
            mins[div].append(-count)
        else:
            mins[div] = [-count]

prod = 1
for div in mins:
    #print(div, len(mins[div]))
    if len(mins[div]) > n - 2:
        counts = sorted(mins[div])[n - 2 :]
        prod *= div**(-counts[0])

#print(mins)
print(prod)