a, b, c = map(int, input().split())
if (a + b + c) % 2 == 1: print('Impossible')
elif a * b * c == 0: print('Impossible')
else:
	x = (a + b - c) // 2
	y = (-a + b + c) // 2
	z = (a - b + c) // 2
	if x < 0 or y < 0 or z < 0: print('Impossible')
	else: print(x,y,z)