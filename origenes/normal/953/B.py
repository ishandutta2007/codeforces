'''s = 'dfhviuehrg'
print(s[0])
print(s[-1])
print('I am a {:^10d} boy'.format(3))

a = [1, 2, 3]
a.extend([2, 3])
a.pop()
a.insert(1, [2, 3])
a.remove(1)
a.reverse()
print(a)

b = list(range(10, 1, -1))
b.sort()
b.reverse()
print(b)

c = (1,)
print(c)

d = [n for n in range(1, 10)]
print(d)

e = {
    'key': 23,
    23 : 'key',
    (1, 2, 3): 123  # Key must be immutable
}

print(e['key'])
del(e[23])
print(23 in e)
e[23] = 'Hihi'
print(23 in e)

it = e.items()
print(it)
del e[23]
print(it)

print(2 + 3)

print(zip('abc', [1, 2, 3]))
print(dict(zip('abc', [1, 2, 3])))

a = {1, 2, 3, 4, 5, 5, 5}
b = {2, 3, 7, 8}

print(a.intersection(b))
print(a.union(b))
print(a.difference(b))
print(a.symmetric_difference(b))

b = 4.5
print(str(b).replace('.', '', 1))


k = 4
print(k)'''


def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)


n = int(input())
x = input().split()
for i in range(n):
    x[i] = int(x[i])
# print(x)

x.sort()
g = 0
for i in range(n - 1):
    g = gcd(g, x[i + 1] - x[i])
print((x[n - 1] - x[0]) // g + 1 - n)