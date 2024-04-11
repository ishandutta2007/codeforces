# pisano period 10^6: p = 15 * 10**5; Fibo(p + 1) = 677449000001; inv(677449, 10**6) = 445049;
n, a, d = [int(s) for s in input().split()]
print(a * 445049 * 15*10**5 + 1, d * 445049 * 15*10**5)