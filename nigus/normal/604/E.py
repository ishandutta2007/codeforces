def solve(x, k):
    if k%2 == 0:
        if x <= 2:
            return x;
        return (x+1)%2
    else:
        if x == 3 or x == 1:
            return 1
        if x%2 == 1:
            return 0
        if x == 0 or x == 2:
            return 0
        twos = 1
        while x%2 == 0:
            twos += 1
            x //= 2
        if x == 3:
            twos += 1
        return (twos%2)+1

(n, k) = map(int, input().split())
A = list(map(int, input().split()))
x = 0
for a in A:
    x ^= solve(a,k)
if x == 0:
    print("Nicky")
else:
    print("Kevin")