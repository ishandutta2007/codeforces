n = int(input())
a = list(map(int, input().split()))
s = sum(a)
cur_s = 0
for i in range(n):
    cur_s += a[i]
    if (cur_s * 2 >= s):
        print(i + 1)
        break