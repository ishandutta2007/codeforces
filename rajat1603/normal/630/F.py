pascal = [[0 for x in range(800)] for x in range(800)]
pascal[0][0] = 1
for i in range(1 , 800):
    pascal[i][0] = 1
    for j in range(1 , 8):
        pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j]
n = input()
ans = 0
for i in range(5 , 8):
    ans += pascal[n][i]
print ans