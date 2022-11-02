n = int(input())
ans = 'blue'
locked = False
for i in range(n):
    s = input()
    if s == 'lock':
        locked = True
    elif s == 'unlock':
        locked = False
    else:
        if not locked:
            ans = s
print(ans)