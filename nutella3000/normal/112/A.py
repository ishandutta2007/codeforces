a = input().lower()
b = input().lower()

for i in range(len(a)):
    if a[i] < b[i]:
        print(-1), exit()
    elif a[i] > b[i]:
        print(1), exit()
print(0)