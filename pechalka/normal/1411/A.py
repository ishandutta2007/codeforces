t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    i = len(s) - 1
    while i >= 0 and s[i] == ')':
        i -= 1
    x = len(s) - i - 1
    if x > len(s) - x:
        print("Yes")
    else:
        print("No")