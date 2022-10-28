n = input()
ans = 0
one = 0
cur = map(int , raw_input().split())
for i in range(0 , n) :
    one += cur[i]
    ans += (1 - cur[i]) * one
print ans