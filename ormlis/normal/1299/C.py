n = int(input())
a = list(map(int, input().split()))
c = []
for el in a:
    c.append((el, 1))
    while len(c) > 1 and c[-1][0] * c[-2][1] < c[-2][0] * c[-1][1]:
        c[-2] = (c[-2][0] + c[-1][0], c[-2][1] + c[-1][1])
        c.pop()

ans = []
for el in c:
    ans.extend([str(el[0] / el[1])] * el[1])
print('\n'.join(ans))