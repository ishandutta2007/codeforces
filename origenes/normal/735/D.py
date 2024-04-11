import math
s=int(input())
def is_prime(n):
    upp=int(math.sqrt(n)+0.5)
    for i in range(2, upp+1):
        if(not (n%i)):
            return False
    return True
def tax(n):
    if(is_prime(n)):
        return 1
    if(not (n%2)):
        return 2
    if(is_prime(n-2)):
        return 2
    return 3
print(tax(s))