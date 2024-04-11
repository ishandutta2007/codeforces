def main():
    n, k = map(int, input().split())
    if n == 1 and k == 1:
        return print(0)
    s = list(input())
    if s[0] > '1' and k:
        s[0] = '1'
        k -= 1
    for i in range(1, n):
        if k == 0:
            break
        if s[i] != '0':
            s[i] = '0'
            k -= 1
    print(*s, sep='')


main()