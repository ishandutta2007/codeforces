import sys,os

def gcd(a,b):
    if b==0:return a
    while a>0:
        a,b = b%a,a
    return b

hex2bin = ['']*256
hex2bin[ord('0')] = b'0000'
hex2bin[ord('1')] = b'0001'
hex2bin[ord('2')] = b'0010'
hex2bin[ord('3')] = b'0011'
hex2bin[ord('4')] = b'0100'
hex2bin[ord('5')] = b'0101'
hex2bin[ord('6')] = b'0110'
hex2bin[ord('7')] = b'0111'
hex2bin[ord('8')] = b'1000'
hex2bin[ord('9')] = b'1001'
hex2bin[ord('A')] = b'1010'
hex2bin[ord('B')] = b'1011'
hex2bin[ord('C')] = b'1100'
hex2bin[ord('D')] = b'1101'
hex2bin[ord('E')] = b'1110'
hex2bin[ord('F')] = b'1111'

inp = os.read(0,os.fstat(0).st_size).splitlines()
n = int(inp[0])
buckets = [0]*(n+1)

prev = b''
count = 0
for ind in range(n):
    line = inp[ind+1]
    if line==prev:
        count += 1
    else:
        buckets[count] += 1
        count = 1
        prev = line

        prev_c = b''
        counter = 0
        for byte in prev:
            for c in hex2bin[byte]:
                if c==prev_c:
                    counter += 1
                else:
                    buckets[counter] += 1
                    counter = 1
                    prev_c = c
        buckets[counter] += 1
    if buckets[1]!=0 or (buckets[2]!=0 and buckets[3]!=0):
        print(1)
        sys.exit()

buckets[count] += 1

x = 0
for i in range(1,n+1):
    if buckets[i]:
        while i:
            i,x=x%i,i
print(x)