N = int(input())
slimes = [int(s) for s in input().split()]

all_same = True

for i in range(N - 1):
    if (slimes[i] > 0) != (slimes[i + 1] > 0):
        all_same = False

if N == 1:
    print(slimes[0])
else:
    slimes = [abs(x) for x in slimes]
    print(sum(slimes) - (2 * min(slimes) if all_same else 0))