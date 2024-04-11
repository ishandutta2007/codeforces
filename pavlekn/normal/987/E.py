def main():
    n = int(input())
    if (n == 5):
        print("Petr")
        return
    a = list(map(int, input().split()))
    count = 0
    for i in range(n):
        if (a[i] == i + 1):
            count += 1
    if (count < (n // 1000)):
        print("Um_nik")
    else:
        print("Petr")
main()