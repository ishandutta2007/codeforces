t = int(input())




def solve():
    s, c = input().split()
    a = sorted(s)
    b = ''
    j = 0
    for i in range(len(s)):
        if s[i] != a[i]:
            b = a[i]
            j = i
            break
    for i in range(len(s) - 1, -1, -1):
        if s[i] == b:
            s = s[:j] + s[i] + s[j + 1:i] + s[j] + s[i + 1:]
            break
    if s < c:
        print(s)
    else:
        print('---')



for i in range(t):
    solve()