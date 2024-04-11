from decimal import *
getcontext().prec = 600
x, y, z = map(float , raw_input().split())
x = Decimal(x)
y = Decimal(y)
z = Decimal(z)
val = [Decimal(0) for i in range(12)]
val[0] = ((Decimal(x).log10()) * Decimal(Decimal(y) ** Decimal(z)))
val[1] = ((Decimal(x).log10()) * Decimal(Decimal(z) ** Decimal(y)))
val[2] = ((Decimal(x).log10()) * Decimal(Decimal(y) * Decimal(z)))
val[3] = ((Decimal(x).log10()) * Decimal(Decimal(y) * Decimal(z)))
val[4] = ((Decimal(y).log10()) * Decimal(Decimal(x) ** Decimal(z)))
val[5] = ((Decimal(y).log10()) * Decimal(Decimal(z) ** Decimal(x)))
val[6] = ((Decimal(y).log10()) * Decimal(Decimal(x) * Decimal(z)))
val[7] = ((Decimal(y).log10()) * Decimal(Decimal(x) * Decimal(z)))
val[8] = ((Decimal(z).log10()) * Decimal(Decimal(x) ** Decimal(y)))
val[9] = ((Decimal(z).log10()) * Decimal(Decimal(y) ** Decimal(x)))
val[10] = ((Decimal(z).log10()) * Decimal(Decimal(x) * Decimal(y)))
val[11] = ((Decimal(z).log10()) * Decimal(Decimal(x) * Decimal(y)))
maxval = Decimal(-11111111111111111111111)
for i in range(12):
    if val[i] > maxval:
        maxval = val[i]
arr = ["" for i in range(12)]
arr[0] = "x^y^z"
arr[1] = "x^z^y"
arr[2] = "(x^y)^z"
arr[3] = "(x^z)^y"
arr[4] = "y^x^z"
arr[5] = "y^z^x"
arr[6] = "(y^x)^z"
arr[7] = "(y^z)^x"
arr[8] = "z^x^y"
arr[9] = "z^y^x"
arr[10] = "(z^x)^y"
arr[11] = "(z^y)^x"
for i in range(12):
    if val[i] == maxval:
        print (arr[i])
        break