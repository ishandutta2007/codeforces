ls = [[1],
[1, 2, 4, 3],
[1, 3, 4, 2],
[1, 4]]

n = int(input())
ans = 0
for i in range(4):
    ans += ls[i][n % len(ls[i])]
    
print (ans % 5)