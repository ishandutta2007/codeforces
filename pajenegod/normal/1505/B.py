import sys
range = xrange
input = raw_input

def f(A):
    x = sum(int(x) for x in A)
    if x > 9:
        return f(str(x))
    return x
print f(input())