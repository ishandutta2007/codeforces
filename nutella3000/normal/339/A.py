s = input()
o = [s.count('1'), s.count('2'), s.count('3')]

t = ''
for i in range(3):
    for j in range(o[i]):
        t += str(i+1) + '+'
print(t[:-1])