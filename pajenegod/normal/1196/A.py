n = int(input())
for _ in range(n):
    print(sum(int(x) for x in input().split())//2)