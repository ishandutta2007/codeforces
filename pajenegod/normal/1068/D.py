import os
from io import BytesIO
range = xrange
input = BytesIO(os.read(0, os.fstat(0).st_size)).readline

MOD = 998244353

# "Crazy method"
MODF = 1.0*MOD
MODF_inv = 1.0/MODF
SHRT = 1.0*(1 << 16)
SHRT_inv = 1.0/SHRT
MAGIC = float(2**52+2**51)
ffloor = lambda x:(x+MAGIC)-MAGIC
modder = lambda a:a - MODF * ffloor(MODF_inv*a)
mod_prod = lambda a, b:\
    modder(modder(a * SHRT) * ffloor(SHRT_inv*b) + a*(b-SHRT * ffloor(b*SHRT_inv)))

def main():
    n = int(input())
    a = [int(i) for i in input().split()]

    f0, f1 = [1.0] * 201, [0.0] * 201
    nf0, nf1 = [0.0] * 201, [0.0] * 201
    for i in range(n):
        if a[i] == -1:
            for j in range(200):
                nf0[j + 1] = modder(nf0[j] + f0[j] + f1[j])
                nf1[j + 1] = modder(nf1[j] - f0[j] + f0[j + 1] - f1[j] + f1[200])
        else:
            for j in range(200):
                nf0[j + 1], nf1[j + 1] = nf0[j], nf1[j]
                if j + 1 == a[i]:
                    nf0[j + 1] = modder(nf0[j] + f0[j] + f1[j])
                    nf1[j + 1] = modder(nf1[j] - f0[j] + f0[j + 1] - f1[j] + f1[200])
        f0, f1, nf0, nf1 = nf0, nf1, f0, f1
        nf0[0]=0.0

    os.write(1, str(int(modder(f1[200]))%MOD))


if __name__ == '__main__':
    main()