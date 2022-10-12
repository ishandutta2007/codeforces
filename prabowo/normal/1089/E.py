ans = [(0, i) for i in range(8)]
ans.extend([(i, 7) for i in range(1, 7)])

for i in range(6, 0, -1):
    ans.extend([(i, j) for j in range(6, -1, -1)] if i % 2 == 0 else [(i, j) for j in range(7)])

ans.extend([(7, j) for j in range(6, -1, -1)])
ans.append((7, 7))

n = int(input())

if n > 56:
    ans = ans[:n] + [(7, 7)]
elif ans[n-2][1] == 7:
    ans = ans[:n-1]
    if ans[-1][0] == 6:
        ans.pop()
        ans.extend([(ans[-1][0], 6), (7, 6), (7, 7)])
    else:
        ans.extend([(6, 7), (7, 7)])
else:
    ans = ans[:n-1]
    ans.append((7, ans[-1][1]))
    ans.append((7, 7))

print(*[chr(ord('a') + i) + str(j+1) for i, j in ans])