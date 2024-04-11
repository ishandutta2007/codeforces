m , n = map(int , raw_input().split())
ans = 0.0
for i in range(1 , m + 1):
    ans += 1.0 * i * (pow(1.0 * i / m , n) - pow(1.0 * (i - 1) / m , n))
print "%.6f" %ans