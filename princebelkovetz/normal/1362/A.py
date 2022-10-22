from sys import stdin, stdout, setrecursionlimit
# plz solve div2c
input = stdin.readline
def ispow(a):
    if a == 1:
        return True
    elif a % 2 == 1:
        return False
    else:
        return ispow(a // 2)


for _ in range(int(input())):
    a, b = map(int, input().split())
    if a == b:
        print(0)
    else:
        if a < b:
            a, b = b, a
        if a % b != 0 or not ispow(a // b):
            print(-1)
        else:
            x = a // b
            ans = 0
            while x >= 8:
                ans += 1
                x //= 8
            while x >= 4:
                ans += 1
                x //= 4
            while x >= 2:
                ans += 1
                x //= 2
            print(ans)