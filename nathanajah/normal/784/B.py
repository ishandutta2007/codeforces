n = int(input())

hexa = hex(n)


x = {
    '0': 1,
    '1': 0,
    '2': 0,
    '3': 0,
    '4': 1,
    '5': 0,
    '6': 1,
    '7': 0,
    '8': 2,
    '9': 1,
    'a': 1,
    'b': 2,
    'c': 0,
    'd': 1,
    'e': 0,
    'f': 0
}

def toInt(c):
    return x[c]


print(sum(map(toInt, hexa[2:])))