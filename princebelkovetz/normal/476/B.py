from sys import stdin, stdout, setrecursionlimit
s = input()
t = input()
cou1 = cou2 = cou3 = 0
for x in s:
    if x == '+': cou1 += 1
    else: cou1 -= 1
a = b = 0
def rec(i, k):
    global a
    global b
    if i == len(k) - 1:
        if k[i] != '?':
            # print(k)
            cou = 0
            for x in k:
                if x == '-':
                    cou -= 1
                else:
                    cou += 1
            if cou == cou1: a += 1
            b += 1
        else:
            rec(i, k[:-1] + '+')
            rec(i, k[:-1] + '-')
    else:
        if k[i] != '?':
            rec(i + 1, k)
        else:
            rec(i + 1, k[:i] + '-' + k[i + 1:])
            rec(i + 1, k[:i] + '+' + k[i + 1:])
rec(0, t)
print(a / b)