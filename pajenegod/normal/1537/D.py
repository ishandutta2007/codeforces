import sys
range = xrange
input = raw_input

def is_odd_power_of_2(n):
    i = 1
    j = 0
    while i < n:
        i *= 2
        j += 1

    return n == i and j & 1

t = int(input())
for _ in range(t):
    n = int(input())
    if n % 2 == 0 and not is_odd_power_of_2(n):
        print 'Alice'
    else:
        print 'Bob'