
n = int(input())
print("\n".join('*'*abs(i) + 'D'*(n - 2 * abs(i)) + '*'*abs(i) for i in range(-(n // 2), n // 2 + 1)))
exit()

s = input()
if len(s) > 2:
  s = s[-2:]
n = int(s)
print((1 + 2**n + 3**n + 4**n) % 5)
exit()


n = int(input())
for i in range(n):
  x, y = map(int, input().split())
  if x != y:
    print('Happy Alex')
    exit()
print('Poor Alex')