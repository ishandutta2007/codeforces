import sys
import string
range = xrange
input = raw_input

alpha = string.ascii_lowercase

s = input()
n = len(s)

before = []
after = []

switch = 1
for _ in range(3):
    i = 0
    count = 0
    out = []
    while len(out)<n:
        out.append(alpha[i])
        count += 1
        if count == switch:
            count = 0
            i = (i+1)%26
    before.append(''.join(out))
    print '?',before[-1]
    after.append(input())
    switch *= 26

before_mapper = {}
for i in range(n):
    before_mapper[before[0][i],before[1][i],before[2][i]] = i
perm = [-1]*n
for i in range(n):
    perm[before_mapper[after[0][i],after[1][i],after[2][i]]] = i

print '!',''.join([s[i] for i in perm])