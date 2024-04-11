import sys
range = xrange
input = raw_input

MOD = 10**9 + 7

inp = sys.stdin.read().split(); ii = 0

S = [ord(c) - 48 for c in inp[ii]]; ii += 1
q = int(inp[ii]); ii += 1

adder = [i for i in range(10)]
multer = [10]*10

ii += q - 1
for _ in range(q):
    dig,A = inp[ii].split('->'); ii -= 1
    dig = ord(dig) - 48
    A = [ord(c) - 48 for c in A]

    add = 0
    mult = 1
    for a in A:
        add = (add * multer[a] + adder[a]) % MOD
        mult = (mult * multer[a]) % MOD
    
    adder[dig] = add
    multer[dig] = mult

ans = 0
for a in S:
    ans = (ans * multer[a] + adder[a]) % MOD
print ans