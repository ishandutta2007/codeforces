input = raw_input
range = xrange

n = int(input())

S = []
#H = []
rat = []
#bonus = 0
for _ in range(n):
    s = input()
    S.append(s)
    num_s = s.count('s')
    num_h = s.count('h')
#    S.append(num_s)
#    H.append(num_h)
    if num_h>0:
        rat.append(float(num_s)/num_h)
    else:
        rat.append(10000000)
#    a = 0
#    b = 0
#    for i in range(len(s)):
#        if s[i] == 's':
#            a+=1
#        else:
#            b+=a
#    bonus += b

order = list(range(n))
order.sort(reverse=True,key=lambda i:rat[i])

dum = []
for i in order:
    dum.append(S[i])
dum = ''.join(dum)

a = 0
b = 0
for c in dum:
    if c=='s':
        a+=1
    else:
        b+=a
print b