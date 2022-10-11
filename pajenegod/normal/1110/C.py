import sys
range = xrange
input = raw_input

def gcd(a,b):
    if a==0:return b
    while b!=0:
        a,b = b,a%b
    return a
#for i in range(2,26):
#    testar = 2**i-1
#    print bin(max([gcd(i,testar-i) for i in range(1,testar)]))


opt = ['tom','0b1',
'0b1',
'0b1',
'0b101',
'0b1',
'0b10101',
'0b1',
'0b1010101',
'0b1001001',
'0b101010101',
'0b1011001',
'0b10101010101',
'0b1',
'0b1010101010101',
'0b1001001001001',
'0b101010101010101',
'0b1',
'0b10101010101010101',
'0b1',
'0b1010101010101010101',
'0b1001001001001001001',
'0b101010101010101010101',
'0b101011100100110001',
'0b10101010101010101010101',
'0b100001000010000100001']



out = []
q = int(input())
for _ in range(q):
    a = int(input())
    binrepr = bin(a)[2:]
    if any(b=='0' for b in binrepr):
        print 2**len(binrepr)-1
    else:
        n = len(binrepr)
        print int(opt[n],2)