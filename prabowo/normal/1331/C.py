# And after happily lived ever they
# and they lived happily ever after

d = {
  0: 4,
  1: 1,
  2: 3,
  3: 2,
  4: 0,
  5: 5,
  6: 6,
  7: 7,
}

n = int(input())

ans = 0
for i in range(8):
    if n >> i & 1:
        ans += 1 << d[i]

print(ans)