A, B, C, D, ans = [int(s) for s in input().split()] + [0]
for z in range(C, D+1):
    l, r = B - min(z-B+1, B) + 1, B - max(z-C+1, A) + 1
    ans += (B-A+1) * (min(A, z-B+2) - (z-C+1)) if z-C+1 < A else 0
    ans += (l + r) * (r - l + 1) // 2 if l <= r else 0
print(ans)