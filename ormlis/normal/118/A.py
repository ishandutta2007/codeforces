s = input().lower()
g = set('aoyeui')
for i in s:
    if i not in g:
        print('.' + i, end='')