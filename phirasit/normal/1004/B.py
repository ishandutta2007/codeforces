n, d = map(int, input().split())
print (''.join([chr(ord('0') + i % 2) for i in range(n)]))