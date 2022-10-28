mod = 10 ** 9 + 7
n , m = map(int , raw_input().split())
print (pow(2 * (n + 1) , m - 1 , mod) * (n + 1 - m) * 2) % mod