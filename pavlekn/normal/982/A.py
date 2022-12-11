n = int(input())
a = input()
e = True
if (n == 1 and a == "0"):
    e = False
if (n > 1 and (a[0] == a[1] == '0' or a[n - 1] == a[n - 2] == '0')):
    e = False
for i in range(1, n):
    if (a[i - 1] == a[i] == '1'):
        e = False
for i in range(2, n):
    if (a[i - 2] == a[i - 1] == a[i] == '0'):
        e = False
if (e):
    print("Yes")
else:
    print("No")