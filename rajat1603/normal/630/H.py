pascal = [[0 for x in range(550)] for x in range(550)]
pascal[0][0] = 1
for i in range(1 , 550):
    pascal[i][0] = 1
    for j in range(1 , i + 1):
        pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j]
n = input()
ans = pascal[n][5] * pascal[n][5] * 120
print ans