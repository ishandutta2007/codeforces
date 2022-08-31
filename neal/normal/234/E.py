input = open("input.txt", "r")
output = open("output.txt", "w")

N = int(input.readline())
X, A, B, C = map(int, input.readline().split())
teams = []

def random():
    global X
    X = (A * X + B) % C
    return X

for i in xrange(N):
    name, rating = input.readline().split()
    teams.append((name, int(rating)))

teams.sort(key=lambda team: team[1], reverse=True)
M = N // 4

baskets = [[] for i in xrange(4)]

for i in xrange(N):
    baskets[i // M].append(teams[i][0])

for i in xrange(M):
    output.write('Group ' + chr(ord('A') + i) + ':\n')

    for j in xrange(4):
        index = random() % len(baskets[j])
        output.write(str(baskets[j].pop(index)) + '\n')