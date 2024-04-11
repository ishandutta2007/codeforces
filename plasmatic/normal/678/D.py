a, b, n, x = map(int, input().split())
mod = int(1e9) + 7

def comb(f, g): # f(g(n))
    return (f[0] * g[0] % mod, (f[0] * g[1] + f[1]) % mod)

def exp(fun, n):
    res = (1, 0)
    cp = fun
    for i in range(0, 63):
        if (n >> i) & 1:
            res = comb(cp, res)
        cp = comb(cp, cp)
    return res
    
ans = exp((a, b), n)
print((ans[0] * x + ans[1]) % mod)