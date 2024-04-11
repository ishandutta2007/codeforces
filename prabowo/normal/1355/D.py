n, s = [int(s) for s in input().split()]
print('NO' if n*2 > s else 'YES\n' + '2 ' * (n-1) + '{}\n{}\n'.format(2 + s - n*2, 1))