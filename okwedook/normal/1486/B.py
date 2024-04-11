t = int(input())
def solve(x):
    x.sort()
    return x[len(x) // 2] - x[(len(x) - 1) // 2] + 1
for i in range(t):
    n = int(input())
    x, y = [], []
    for j in range(n):
        px, py = map(int, input().split())
        x.append(px)
        y.append(py)
    print(solve(x) * solve(y))