n = int(input())
a = list(map(int, input().split()))
sum = 0
for i in range(n):
    sum += abs(a[i])
print(sum)