n, a, b = map(int, input().split())
s = input().split("*")
count = 0
for i in range(len(s)):
    k = len(s[i])
    if (k != 0):
        pr = 0
        if (a > b):
            if (a > 0):
                a -= 1
                k -= 1
                count += 1
                pr = 1
        else:
            if (b > 0):
                b -= 1
                k -= 1
                count += 1
                pr = 2
        while (k > 0):
            if (pr == 1):
                if (b > 0):
                    b -= 1
                    pr = 2
                    count += 1
                else:
                    pr = 0
            elif (pr == 2):
                if (a > 0):
                    a -= 1
                    pr = 1
                    count += 1
                else:
                    pr = 0
            else:
                if (a > b):
                    if (a > 0):
                        a -= 1
                        count += 1
                        pr = 1
                    else:
                        pr = 0
                else:
                    if (b > 0):
                        b -= 1
                        count += 1
                        pr = 2
                    else:
                        pr = 0
            k -= 1
print(count)