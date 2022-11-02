s = input()
t = ''
for i in s.lower():
    if i not in 'aoyeui':
        t += '.' + i
print(t)