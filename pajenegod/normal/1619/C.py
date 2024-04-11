def solve(a,s):
    b = []
    while a and s:
        lasta = a.pop()
        lasts = s.pop()
        
        if lasta <= lasts:
            b.append(lasts - lasta)
        else:
            if not s:
                return False
            b.append(lasts + s.pop() * 10 - lasta)
    else:
        if a or s or any(x < 0 or x > 9 for x in b):
            return False
        else:
            return int(''.join(str(x) for x in b[::-1]))

t = int(input())
for _ in range(t):
    a, s = [[int(c) for c in x] for x in input().split()]

    for i in range(20):
        b = solve([0] * i + a, s[:])
        if b:
            print(b)
            break
    else:
        print(-1)