import sys
primes = [2,3,5,7,11,13,17,19,23,29 
,31,37,41,43,47]
div = []
for p in primes:
    print(p)
    sys.stdout.flush()
    ans = input()
    if ans == "yes":
        div.append(p)

if len(div)>1:
    print("composite") # Of atleast two different primes
elif len(div)==0:
    print("prime") # Never found a divisor<50, therefore it is prime
else:
    if div[0]**2>100:
        print('prime')
    else:
        print(div[0]**2)
        sys.stdout.flush()
        ans = input()
        if ans == "yes":
            print("composite")
        else:
            print("prime")