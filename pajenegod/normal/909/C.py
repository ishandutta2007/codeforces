n = int(input())
a = [input() for _ in range(n)]

MOD = int(1e9+7)
const = 5001
levels = [0]*const
levels[0] = 1

for i in range(n-1):
    if a[i]=='f':
        for j in range(const-2,-1,-1):
            levels[j+1]=levels[j]
        levels[0]=0
    else:
        cumsum = 0
        for j in range(const-1,-1,-1):
            cumsum += levels[j]
            cumsum%=MOD
            levels[j]=cumsum
print(sum(levels)%MOD)