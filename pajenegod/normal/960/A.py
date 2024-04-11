import sys
range = xrange
input = raw_input

s = input()
n = len(s)
a_count = 0
i = 0
while i<n and s[i]=='a':
    i+=1
    a_count += 1
b_count = 0
while i<n and s[i]=='b':
    i+=1
    b_count += 1
c_count = 0

while i<n and s[i]=='c':
    i+=1
    c_count += 1

if i<n or a_count == 0 or b_count == 0 or not (a_count == c_count or b_count == c_count):
    print('NO')
else:
    print('YES')