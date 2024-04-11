n = int(input())
fib = [1, 1]
mv = 100

for i in range(2, mv):
    fib.append(fib[i - 1] + fib[i - 2])

# print(fib)

ans = 0
for i in range(mv):
    if fib[i] > n:
        ans = i - 2
        break
print(ans)