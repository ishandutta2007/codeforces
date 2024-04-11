N = int(raw_input())
flats = raw_input()
pokemon_types = set()

for pokemon in flats:
	pokemon_types.add(pokemon)

freq = {}

for pokemon in pokemon_types:
	freq[pokemon] = 0

zeroes = len(pokemon_types)

i, j = 0, 0
best = N

while i < N:
	while j < N and zeroes > 0:
		pokemon = flats[j]

		if freq[pokemon] == 0:
			zeroes -= 1

		freq[pokemon] += 1
		j += 1

	if zeroes == 0:
		best = min(best, j - i)

	pokemon = flats[i]
	freq[pokemon] -= 1

	if freq[pokemon] == 0:
		zeroes += 1

	i += 1

print best