input= raw_input
range = xrange
fib = [1,1]
for i in range(100):
    fib.append(fib[-1]+fib[-2])

fib = set(fib)

n = int(input())

bla = ['o']*n
for i in range(n):
    if i+1 in fib:
        bla[i]='O'
print ''.join(bla)