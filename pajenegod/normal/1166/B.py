import sys
range = xrange
input = raw_input

k = int(input())

vow = ['a','e','i','o','u']

div = []
i = 5
while i*i<k:
    if k%i==0:
        div.append(i)
    i += 1
if i*i == k:
    div.append(i)


for n in div:
    m = k // n
    if n < 5 or m < 5: continue
    
    
    mat = [[0]*n for _ in range(m)]
    for i in range(5):
        for j in range(5):
            mat[i][j] = (i-j)%5

    for i in range(5, m):
        for j in range(n):
            mat[i][j] = j%5

    for i in range(m):
        for j in range(5, n):
            mat[i][j] = i%5
    dum = ''.join(''.join(vow[i] for i in row) for row in mat)
    print dum
    sys.exit()
print -1