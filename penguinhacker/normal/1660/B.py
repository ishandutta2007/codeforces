t=int(input())
for _ in range(t):
    n=int(input())
    a=[int(i) for i in input().split()]
    a.append(0)
    a.sort()
    print('YES' if a[-1]-a[-2]<=1 else 'NO')