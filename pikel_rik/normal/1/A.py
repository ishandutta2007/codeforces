import math

string = str(input())

l = string.split();
n = float(l[0])
m = float(l[1])
a = float(l[2])

print(math.ceil(m / a) * math.ceil(n / a))