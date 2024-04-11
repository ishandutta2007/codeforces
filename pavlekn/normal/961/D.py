def is_line(b):
    if (len(b) < 3):
        return True
    x1 = b[0][0]
    y1 = b[0][1]
    for i in range(len(b)):
        b[i][0] -= x1
        b[i][1] -= y1
    x2 = b[1][0]
    y2 = b[1][1]    
    for i in range(2, len(b)):
        if (x2 * b[i][1] != y2 * b[i][0]):
            return False
    return True
def main():
    n = int(input())
    if (n < 5):
        print("YES")
        return
    a = []
    for i in range(n):
        x, y = map(int, input().split())
        a.append([x, y])
    for i1 in range(3):
        x0 = a[i1][0]
        y0 = a[i1][1]
        for i in range(n):
            a[i][0] -= x0
            a[i][1] -= y0
        if (i1 == 0):
            i2 = 1
            x1 = a[1][0]
            y1 = a[1][1]
        elif (i1 == 1):
            i2 = 2
            x1 = a[2][0]
            y1 = a[2][1]
        else:
            i2 = 0
            x1 = a[0][0]
            y1 = a[0][1]
        b = []
        for i in range(n):
            if (i != i1 and i != i2):
                if (x1 * a[i][1] != y1 * a[i][0]):
                    b.append([a[i][0], a[i][1]])
        if (is_line(b)):
            print("YES")
            return
    print("NO")
main()