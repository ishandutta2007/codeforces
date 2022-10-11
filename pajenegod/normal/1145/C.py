n = int(input())
bits = bin(n+16)[3:]
bits = [int(x) for x in bits]


bits[0] ^= 1

if bits[0]:
    bits[1] ^= 1

if bits[0] and bits[1]:
    bits[2] ^= 1

if bits[0] and bits[1] and bits[2]:
    bits[3] ^= 1
print(int(''.join(str(x) for x in bits),2))