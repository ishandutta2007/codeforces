mod = 10 ** 9 + 7
n , k = map(int , raw_input().split())
print (pow(k , k - 1 , mod) * pow(n - k , n - k , mod)) % mod;