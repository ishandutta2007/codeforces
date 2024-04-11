n = int(input())
a = list(map(int, input().split()))
mex = 1
a.sort()

for num in a:
    if num >= mex:
        mex = mex + 1
print(mex)