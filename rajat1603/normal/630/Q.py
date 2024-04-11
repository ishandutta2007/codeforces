from decimal import *
getcontext().prec = 100
a , b , c = map(int , raw_input().split())
ans1 = Decimal(a * a * a / (6 * ((Decimal(2)).sqrt())))
ans2 = Decimal(b * b * b / (3 * ((Decimal(2)).sqrt())))
ans3 = Decimal((5 + (Decimal(5)).sqrt()) * c * c * c / Decimal(24))
print ans1 + ans2 + ans3