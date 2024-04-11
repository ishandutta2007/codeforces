t = int(input())
for i in range(t):
  n = input()
  a = [x % 2 for x in map(int, input().split())]
  even = a.count(0)
  odd = a.count(1)
  if sum(a) % 2 == 1 or (even > 0 and odd > 0):
    print('YES')
  else:
    print('NO')