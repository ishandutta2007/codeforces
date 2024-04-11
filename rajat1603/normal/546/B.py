n = input()
a = map(int , raw_input().split())
ans = 0
count = [0] * 10000
for i in range (0 , n):
    count[a[i]] += 1
for i in range (0 , 10000):
    while count[i] > 1:
        ans += 1
        count[i] -= 1
        count[i+1] += 1
print ans