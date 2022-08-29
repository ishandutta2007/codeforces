N, M = map(int, raw_input().split())
rows = set()
cols = set()

for i in range(N):
	rows.add(i)
	cols.add(i)

answers = []

for i in range(M):
	x, y = map(lambda x: x - 1, map(int, raw_input().split()))

	if x in rows:
		rows.remove(x)

	if y in cols:
		cols.remove(y)

	answers.append(len(rows) * len(cols))

print ' '.join(map(str, answers))