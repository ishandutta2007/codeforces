import sys

def power2(x):
    return 2 * x == 1 << x.bit_length()


def string_check(x, y):
    i = -1
    while True:
        i = y.find(x, i + 1)
        if i == -1:
            break

        if all(c == '1' for c in y[:i]) and all(c == '1' for c in y[i + len(x):]):
            return True
    return False

def to_binary(x):
    return bin(x)[2:]

def check(x, y):
    if x == y:
        return True

    if x == 0:
        return power2(y + 1)
    
    x1 = (x << 1) + 1
    x0 = x >> (x & -x).bit_length() - 1
    
    
    ybin = to_binary(y)
    if string_check(to_binary(x0), ybin):
        return True
    
    if string_check(to_binary(x0)[::-1], ybin):
        return True
    
    if string_check(to_binary(x1), ybin):
        return True
    
    if string_check(to_binary(x1)[::-1], ybin):
        return True
    
    return False



x,y = [int(x) for x in input().split()]
if check(x,y):
    print('YES')
else:
    print('NO')