q = int(input())
for i in range(q):
    a, b, c = map(int, input().split())
    ans = 3 * 10 ** 9
    for a1 in range(a - 1, a + 2):
        for b1 in range(b - 1, b + 2):
            for c1 in range(c - 1, c + 2):
                ans = min(ans, abs(a1 - b1) + abs(b1 - c1) + abs(c1 - a1))
    
    
    print(ans)