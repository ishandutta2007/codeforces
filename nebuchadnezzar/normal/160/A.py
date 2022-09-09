n = int(raw_input())

mas = list(map(int,raw_input().split()))

#print(mas)
#print(mas.sort())
mas.sort()
mas.reverse()

summ = sum(mas)
s = 0
ans = 1

for i in mas:
    s += i
    if(2 * s > summ):
        print ans
        break
    ans += 1