n = input()
n = n[0] + n[2] + n[4] + n[3] + n[1]

n = str(int(n) ** 5 % 100000)
print ('0' * (5 - len(n)) + n)