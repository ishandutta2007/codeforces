n = int(input())
locked = False
color = 'blue'
for i in range(n):
    a = input()
    if a == 'lock':
        locked = True
    elif a == 'unlock':
        locked = False
    elif not locked:
        color = a
print(color)