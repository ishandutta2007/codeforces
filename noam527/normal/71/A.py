t = int(input())
while t > 0:
    t -= 1
    s = input()
    if len(s) <= 10:
        print(s)
    else:
        print(s[0] + str(len(s) - 2) + s[-1])