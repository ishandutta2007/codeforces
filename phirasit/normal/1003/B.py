a, b, x = map(int, input().split())

ca, cb = '0', '1'
if a < b:
    a, b = b, a
    ca, cb = cb, ca

aa = (x + 2) // 2
bb = (x + 1) // 2

aaa = [ca * (a-aa+1 if i == 0 else 1) for i in range(aa)]
bbb = [cb * (b-bb+1 if i == 0 else 1) for i in range(bb)]

for i in range(aa):
    print (aaa[i], end='')
    if i < bb:
        print (bbb[i-1], end='')

print('')