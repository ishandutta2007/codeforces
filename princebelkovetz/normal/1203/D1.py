from sys import stdin, stdout, setrecursionlimit
# plz solve div2c


s = input()
t = input()
n = len(s)
ans = 0

def hah(string):
    cou = 0
    for x in string:
        if x == t[cou]:
            cou += 1
        if cou == len(t):
            return True
    return False


for i in range(n):
    for j in range(i, n + 1):
        cur = s[:i] + s[j:]
        #print(cur)
        if hah(cur):
            ans = max(ans, n - len(cur))
print(ans)