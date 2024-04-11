n, k = map(int, raw_input().strip().split())
mas = map(int, raw_input().strip().split())
l = 0
r = 0
mas_used = [0] * 100010
mas_used[mas[0]] = 1
num = 1
truely = True
while(num < k):
    r += 1
    if(r == n):
        print "-1 -1"
        truely = False
        break
    if(mas_used[mas[r]] == 0):
        num += 1
    mas_used[mas[r]] += 1
    while(mas_used[mas[l]] > 1):
        mas_used[mas[l]] -= 1
        l += 1

if(truely == True):
    print l + 1, r + 1