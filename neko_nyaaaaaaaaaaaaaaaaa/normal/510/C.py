n = int(input())
edges = [[] for _ in range(26)]
words = []
orders = []
visited = [0] * 26

def dfs(i):
	visited[i] = -1
	for neighbor in edges[i]:
		if visited[neighbor] == -1:
			return False
		if visited[neighbor] == 0:
			if not dfs(neighbor):
				return False
	visited[i] = 1
	orders.append(i)
	return True


for i in range(n):
	word = input()
	words.append(word)

for i in range(n-1):
	index = 0
	foundDiff = False
	while index < len(words[i]) and index < len(words[i+1]):
		# print(words[i], words[i+1])
		if words[i][index] != words[i+1][index]:
			edges[ord(words[i][index]) - ord("a")].append(ord(words[i+1][index]) - ord("a"))
			foundDiff = True
			break
		else:
			index += 1
	if not foundDiff:
		if len(words[i]) > len(words[i+1]):
			print("Impossible")
			exit()

for i in range(26):
	if not visited[i]:
		if not dfs(i):
			print("Impossible")
			exit()

for i in range(26):
	orders[i] = chr(orders[i] + ord("a"))
print("".join(reversed(orders)))