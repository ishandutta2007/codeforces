h, m = map(int, input().split(':'))
h1, m1 = map(int, input().split(':'))
m2 = h * 60 + m
m3 = h1 * 60 + m1
m4 = (m2 + m3) // 2
hn = m4 // 60
mn = m4 % 60
if hn < 10:
    print(0, end='')
print(hn, end=':')
if mn < 10:
    print(0, end='')
print(mn)