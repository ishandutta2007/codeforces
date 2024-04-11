n = int(input())
a = [int(i) for i in input().split()]
b = [a[n - 1]]
for i in range(n - 1, 0, -1):
    b.append(a[i] + a[i - 1])
for i in range(n - 1, -1, -1):
    print(b[i])