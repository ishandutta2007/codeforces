from functools import reduce
print(reduce(lambda x, y: (x * 16 + y) % 1000003, map(lambda c: '><+-.,[]'.find(c) + 8, input()), 0))