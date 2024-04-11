n, k = map(int, input().split())

winter = []
for i, t in enumerate([int(n) for n in input().split()]):
    if (t < 0): winter.append(i)
    
if (len(winter) > k):
    print(-1)
else:
    ans = len(winter)*2
    k -= len(winter)
    for diff in sorted([winter[i] - winter[i-1] - 1 for i in range(1, len(winter))]):        
        if (k >= diff):
            k -= diff
            ans -= 2         
    print(ans - (1 if len(winter) > 0 and k >= n - winter[-1] - 1 else 0))