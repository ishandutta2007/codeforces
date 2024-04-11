n = int(input())
a = list(map(int, input().split()))
if (a == [0] * n):
    print("EASY")
else:
    print("HARD")