input()
ls = list(map(int, input().split()))
print(max(ls) ^ ls[-1])