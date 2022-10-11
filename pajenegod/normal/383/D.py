import sys
range = xrange
input = raw_input

MOD = 10**9 + 7

n = int(input())
A = [int(x) for x in input().split()]
m = 20010

ans = 0

counter = [0] * m
for a in A:
    new_counter = [0]*len(counter)
    counter[0] += 1
    for i in range(len(counter)):
        new_counter[i - a] += counter[i]
        new_counter[i - m + a] += counter[i]
    counter = [x if x < MOD else x - MOD for x in new_counter]
    ans += counter[0]
print ans % MOD