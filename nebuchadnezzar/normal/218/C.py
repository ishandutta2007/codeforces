def dfs(num):
    used[num] = True
    for i in xrange(n):
        if((mas[num][0] == mas[i][0] or mas[num][1] == mas[i][1]) and i != num and used[i] == False):
            dfs(i)
            
    
    
n = input()
mas = [0] * n

for i in xrange(n):
    x, y = map(int, raw_input().strip().split())
    mas[i] = [x, y]



used = [False] * n
count = 0
for i in xrange(n):
    if(used[i] == False):
        dfs(i)
        count += 1

print count - 1