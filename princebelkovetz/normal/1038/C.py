from sys import stdin, stdout, setrecursionlimit

# plz solve div2c
n = int(input())
a = sorted([int(i) for i in input().split()], reverse=True)
b = sorted([int(i) for i in input().split()], reverse=True)
cura = curb = curai = curbi = 0
for i in range(2 * n):
    if i % 2 == 0:
        if curbi == n or (curai < n and a[curai] >= b[curbi]):
            cura += a[curai]
            curai += 1
        else:
            curbi += 1
    else:
        if curai == n or (curbi < n and b[curbi] >= a[curai]):
            curb += b[curbi]
            curbi += 1
        else:
            curai += 1
print(cura - curb)