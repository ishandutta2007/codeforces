import random

n = int(input().strip())

prime = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101]

ans = [] 
def start():
    global ans
    ans = [1] * n
    for p in prime:
        x = random.randint(0, n-1)
        for i in range(n):
            if i != x and random.randint(0, 1) == 0:
                ans[i] *= p

def gcd(a, b):
    if b == 0: return a
    return gcd(b, a % b)

def check():
    g = 0
    for x in ans:
        g = gcd(g, x)
    if g != 1: return False
    for i in range(n):
        for j in range(i+1, n):
            if gcd(ans[i], ans[j]) == 1:
                return False
            if ans[i] == ans[j]:
                return False
    return True

if n == 2:
    print(-1)
    exit()

while True:
    start()
    if check():
        break

for x in ans:
    print (x)