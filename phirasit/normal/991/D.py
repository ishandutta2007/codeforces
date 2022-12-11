data = [list(input().strip()), list(input().strip())]
n = len(data[0])
inf = 10 ** 9

ans = 0
for i in range(n-1):
    a = data[0][i] + data[1][i] + data[0][i+1] + data[1][i+1]
    if a.count('0') >= 3:
        ans += 1
        if data[0][i] == '0': data[0][i] = 'X'
        if data[1][i] == '0': data[1][i] = 'X'
        if data[0][i+1] == '0': data[0][i+1] = 'X'
        if data[1][i+1] == '0' and a != '0000': data[1][i+1] = 'X'

print (ans)