import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(x) for x in input().split()]

    mean = sum(A) // n
    extra = sum(A) - n * mean

    a1_count = n - extra
    a2_count = extra

    a1_val = mean
    a2_val = mean + 1

    ans =  a1_count * (a1_count - 1) // 2 * abs(a1_val - a1_val)
    ans += a2_count * (a2_count - 1) // 2 * abs(a2_val - a2_val)
    ans += a1_count * a2_count * abs(a1_val - a2_val)

    print ans