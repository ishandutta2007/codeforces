import sys

x = float(sys.stdin.readline())
diff = x
for a in range(1, 11):
    for h in range(1, 11):
        t = pow((a*a*h*h)/(a*a+4*h*h), 0.5)

        if diff > abs(x - t):
            diff = abs(x-t)
            ans_a = a
            ans_h = h

print(ans_a, ans_h)