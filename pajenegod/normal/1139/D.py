big = 100010
def gen_mu():
    mu = [1]*big
    mu[0] = 0
    P = [True]*big
    P[0] = P[1] = False
    for i in range(2,big):
        if P[i]:
            j = i
            while j<big:
                P[j] = False
                mu[j] *= -1
                j += i
            j = i*i
            while j<big:
                mu[j] = 0
                j += i*i
    return mu

m = int(input())
mu = gen_mu()

MOD = 10**9+7
def mod_inv(x):
    return pow(x, MOD-2, MOD)

s = 1
for i in range(2,big):
    # p is probabilty that i | a random number [1,m]
    p = (m//i)*mod_inv(m)
    s += (-mu[i])*(p)*mod_inv(1-p)
print(s%MOD)