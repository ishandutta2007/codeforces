n,m,k=map(int,raw_input().split())
grid=[[0 for i in range(m)] for j in range(n)]
st=0
for i in range(n):
    s=raw_input()
    st+=s.count('.')
    for j in range(m):
        grid[i][j]=s[j]
stack=[]
find=False
for i in range(n):
    for j in range(m):
        if grid[i][j]=='.':
            find=True
            break
    if find:
        break
stack.append((i,j))
k=st-k
while k:
    i,j=stack[0]
    stack=stack[1:]
    if grid[i][j]!='.':
        continue
    grid[i][j]='r'
    k-=1
    if i>0:
        if grid[i-1][j]=='.':
            stack.append((i-1,j))
    if i<n-1:
        if grid[i+1][j]=='.':
            stack.append((i+1,j))
    if j>0:
        if grid[i][j-1]=='.':
            stack.append((i,j-1))
    if j<m-1:
        if grid[i][j+1]=='.':
            stack.append((i,j+1))
for i in range(n):
    for j in range(m):
        if grid[i][j]=='.':
            grid[i][j]='X'
        elif grid[i][j]=='r':
            grid[i][j]='.'
for i in range(n):
    print ''.join(grid[i])