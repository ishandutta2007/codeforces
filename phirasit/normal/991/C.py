n = int(input())

lo, hi = 1, n+1
req = (n + 1) // 2

while lo < hi:

    mid = (lo + hi) // 2

    eaten = 0
    candies = n
    while candies > 0:
        val = min(candies, mid)
        eaten += val

        candies -= val
        candies -= candies // 10

    if eaten >= req:
        hi = mid
    else:
        lo = mid + 1

print (lo)