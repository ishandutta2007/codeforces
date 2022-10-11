n,k = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]

h = 100000000000
for a in A:
    if k%a==0:
        h = min(h,k//a)
print(h)