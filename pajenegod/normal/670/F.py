import sys
range = xrange
input = raw_input

S = input()
Sub = input()

if S == '10' or S == '01':
    print '0'
    sys.exit()

a = 1
b = 1000000
while a < b:
    c = a + b >> 1
    if len(str(c)) + c < len(S):
        a = c + 1
    else:
        b = c

counter = [0]*10
ord0 = ord('0')
for c in S:
    counter[ord(c) - ord0] += 1

for c in Sub:
    counter[ord(c) - ord0] -= 1

for c in str(a):
    counter[ord(c) - ord0] -= 1


i = 0
c = Sub[0]
while i<len(Sub) and Sub[i] == c: i += 1

if i==len(Sub) or c <= Sub[i]:
    split = ord(c) - ord0
else:
    split = ord(c) - ord0 - 1


smallest = 1
while smallest < 10 and not counter[smallest]:smallest += 1
if smallest == 10:
    print Sub + '0'*counter[0]
    sys.exit()





#if smallest == ord(c) - ord0 and (c + '0'*counter[0])[:len(Sub)] == Sub:
#    out = [c, '0'*counter[0], Sub]
#    for i in range(smallest + 1,10):
#        out.append(chr(i + ord0)*counter[i])
#    print ''.join(out)
#    sys.exit()



counter[smallest] -= 1
out = [smallest]
for i in range(split + 1):
    for _ in range(counter[i]):
        out.append(i)

out += (ord(c) - ord0 for c in Sub)

for i in range(split + 1, 10):
    for _ in range(counter[i]):
        out.append(i)

S = ''.join(chr(o + ord0) for o in out)
if Sub[0] != '0':
    counter[smallest] += 1
    S = min(S, Sub + ''.join(chr(i + ord0)*counter[i] for i in range(10)))
print S