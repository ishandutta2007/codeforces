n = int(input())
c = 0
for i in range(n):
    c += int(sum(map(int, input().split())) > 1)
print(c)