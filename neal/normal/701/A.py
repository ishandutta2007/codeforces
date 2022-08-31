N = int(raw_input())
cards = map(int, raw_input().split())
goal = 2 * sum(cards) / N

card_finder = {}
card_array_index = {}

for i, card in reversed(list(enumerate(cards))):
	if card not in card_finder:
		card_finder[card] = []
		card_array_index[card] = 0

	card_finder[card].append(i)

done = [False] * N

for i, card in enumerate(cards):
	if not done[i]:
		matching_card = card_finder[goal - card][card_array_index[goal - card]]
		card_array_index[goal - card] += 1
		done[matching_card] = True
		print i + 1, matching_card + 1