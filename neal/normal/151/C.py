N = int(raw_input())
primes = []

def check(div):
    global N
    while N % div == 0:
        primes.append(div)
        N //= div

check(2)
check(3)
div = 5

while div * div <= N:
    check(div)
    div += 2
    check(div)
    div += 4

if N > 1:
    primes.append(N)

if len(primes) <= 1:
    print 1
    print 0
elif len(primes) == 2:
    print 2
else:
    print 1
    print primes[0] * primes[1]