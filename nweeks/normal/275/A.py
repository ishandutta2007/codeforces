l = [list(map(int, input().split())) for y in range(3)]
state = [[True for i in range(3)] for _ in range(3)]

moves = [[-1, 0], [1, 0], [0, -1], [0, 1]]

for i in range(3):
	for j in range(3):
		l[i][j] %= 2
		if l[i][j] == 1:
			state[i][j] = not state[i][j]
			for n in moves:
				if i + n[0] >= 0 and i + n[0] < 3 and j + n[1] >= 0 and j + n[1] < 3:
					state[i + n[0]][j + n[1]] = not state[i + n[0]][j + n[1]]

for i in range(3):
	for j in range(3):
		if state[i][j]:
			print("1", end="")
		else:
			print("0", end="")
	print()