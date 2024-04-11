#  

t = int(input())
for query in range(t):
    a, b = map(int, input().split())
    c = abs(a - b)
    left = -1
    right = 10 ** 9
    while right - left > 1:
        mid = (left + right) // 2
        if mid * (mid + 1) // 2 >= c:
            right = mid
        else:
            left = mid
    while right * (right + 1) // 2 % 2 != c % 2:
        right += 1
    print(right)