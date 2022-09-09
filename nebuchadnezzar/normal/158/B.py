num = int(raw_input())
mas = raw_input().split()
mas2 = [0] * 5
for i in mas:
    mas2[int(i)] += 1

ans = mas2[4]

ans += mas2[3]

if(mas2[1] > mas2[3]):
    mas2[1] -= mas2[3]
else:
    mas2[1] = 0

ans += (mas2[2] / 2)

if(mas2[2] % 2 == 1):
    if(mas2[1] > 2):
        mas2[1] -= 2
    else:
        mas2[1] = 0
    ans += 1

ans += ((mas2[1] + 3) / 4)

print ans