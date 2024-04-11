(n,k) = map(int, input().split())
arr = list(map(int, input().split()))
newarr = []

arr.sort()
used = 0

for tmp in arr:
    if used < k and tmp < 0:
        newarr.append(-tmp)
        used += 1
    else:
        newarr.append(tmp)

now = sum(newarr)
if (k - used) % 2 == 1:
    now -= 2*min(newarr)

print(now)