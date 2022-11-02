n, t = int(input()), input()[:: 2]
p, r = {i: 0 for i in '0123456789'}, '-1'
for i in t:
    p[i] += 1
if p['0']:
    t = ['147', '258']
    x = [sum(p[i] for i in k) for k in t]
    d = x[0] % 3 - x[1] % 3
    if d:
        (d, t) = (1, t[d > 0]) if abs(d) == 2 and x[d > 0] else (abs(d), t[d < 0])
        for i in t:
            if p[i] > 0:
                if p[i] < d: p[i], d = 0, 1
                else: p[i] -= d; break
    r = ''.join(i * p[i] for i in '9876543210')
    if r[0] == '0': r = '0'
print(r)