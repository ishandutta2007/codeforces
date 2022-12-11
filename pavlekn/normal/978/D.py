def f(start, step):
    b = [start]
    for i in range(n - 1):
        b.append(b[-1] + step)
    count = 0
    for i in range(n):
        if (abs(a[i] - b[i]) == 1):
            count += 1
        elif (abs(a[i] - b[i]) > 1):
            return -1
    return count
n = int(input())
a = list(map(int, input().split()))
def main():
    e = 10 ** 9
    if (n == 1):
        print(0)
        return
    for i in range(a[0] - 1, a[0] + 2):
        for j in range(a[1] - a[0] - 2, a[1] - a[0] + 3):
            ne = f(i, j)
            if (ne != -1):
                e = min(e, ne)
    if (e == 10 ** 9):
        print(-1)
    else:
        print(e)
main()