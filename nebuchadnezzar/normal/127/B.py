import sys
a = input()
m = sys.stdin.readline().split(" ")
n = [0]*120
for i in m:
    n[int(i)] += 1

num = 0
for i in range(120):
    num = num + (n[i] // 2)
num = num // 2
print(num)