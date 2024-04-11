from sys import stdin, stdout, setrecursionlimit

# plz solve div2c
n = int(input())
a = sorted([(int(i)) for i in input().split()])
minus = plus = 0
for x in a:
    if x <= 0: minus += 1
    else: plus += 1
if n == 1:
    print(a[0])
elif plus > 0 and minus > 0:
    a = [abs(x) for x in a]
    print(sum(a))
elif plus == 0:
    print(-sum(a) + max(a) * 2)
elif minus == 0:
    print(sum(a) - min(a) * 2)