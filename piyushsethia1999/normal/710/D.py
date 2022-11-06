def gcd(a, b):
    if (a == 0):
        return [0, 1, b];
    res = gcd(b%a, a);
    d = res[2]
    x1 = res[0]
    y1 = res[1]
    return [y1 - (b // a) * x1, x1, d];

def find_any_solution(a, b, c):
    res = gcd(abs(a), abs(b))
    g = res[2]
    x0 = res[0]
    y0 = res[1]
    if (c % g != 0):
        return [False, 0, 0, 0]
    x0 *= (c // g);
    y0 *= (c // g);
    if (a < 0):
        x0 = -x0;
    if (b < 0):
        y0 = -y0;
    return [True, x0, y0, g];
# print(map(int, raw_input().split()))
a1, b1, a2, b2, L, R = map(int, raw_input().split())
bo, l, r, g = find_any_solution(a1, a2, b2 - b1)
# print(bo, l, r)
if bo:
    aa = a1 * l + b1
    dd = (a1 * a2) // g
    bb = max(b1, b2)
    ll = (bb - aa + dd - 1) // dd
    aa = aa + dd * ll
    oo = max((L - aa + dd - 1) // dd, 0)
    op = (R - aa) // dd
    print(max(op - oo + 1, 0))
else:
    print(0)