input()
A = sorted(list(map(int, input().split())))
keep = max(A)
up_to = 0

for a in A:
    if a > up_to:
        up_to += 1
    else:
        keep += 1

print(sum(A) - keep)