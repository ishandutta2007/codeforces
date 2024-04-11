from math import sqrt
from decimal import *
getcontext().prec = 600
a , b , c = map(float , raw_input().split())
a = Decimal(a)
b = Decimal(b)
c = Decimal(c)
d = Decimal(b * b - Decimal(4) * a * c)
solve1 =  (-b + d.sqrt()) / (Decimal(2) * a)
solve2 =  (-b - d.sqrt()) / (Decimal(2) * a)
print max(solve1 , solve2)
print min(solve1 , solve2)