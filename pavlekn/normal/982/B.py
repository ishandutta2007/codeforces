from collections import deque
def main():
    n = int(input())
    a = list(map(int, input().split()))
    s = input()
    b = []
    for i in range(n):
        b.append([a[i], i + 1])
    b.sort()
    ans = []
    count1, count2 = 0, 0
    c = deque([])
    for i in range(2 * n):
        if (s[i] == '0'):
            ans.append(b[count1][1])
            c.append(b[count1][1])
            count1 += 1
        else:
            ans.append(c[-1])
            c.pop()
            count2 += 1
    for i in range(2 * n):
        print(ans[i], end=' ')
main()