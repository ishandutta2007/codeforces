def prime_factors(n):
    i = 2
    factors = []
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors.append(i)
    if n > 1:
        factors.append(n)
    return factors

def factors(n):
    super=[1]
    for i in prime_factors(n):
        super.extend([j*i for j in super])
    return list(sorted(set(super)))
    
n = int(input())
n -= 1
OK = False;
for i in factors(n):
    if((n // i - i) > 0 and (n // i - i) % 2 == 1 and i > 0 and (n // i - i)// 2 > 0):
        print("{} {}".format(i, (n // i - i)// 2))
        OK = True
        break
if(not OK):
    print("NO")