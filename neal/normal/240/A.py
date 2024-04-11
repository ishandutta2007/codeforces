input = open("input.txt", "r")
output = open("output.txt", "w")

M, K = map(int, input.readline().split())
favorites = map(int, input.readline().split())
is_favorite = [False for i in xrange(M)]

for f in favorites:
    is_favorite[f - 1] = True

N = int(input.readline())
movies = []

def evaluate(actors):
    fav = 0
    zeroes = 0

    for a in actors:
        if a >= 0:
            fav += 1 if is_favorite[a] else 0
        else:
            zeroes += 1

    values = []

    for i in xrange(M):
        if i not in actors:
            values.append(1 if is_favorite[i] else 0)

    values.sort()
    return (fav + sum(values[:zeroes]), fav + sum(values[max(len(values) - zeroes, 0):]))

for i in xrange(N):
    name = input.readline()
    n = int(input.readline())
    actors = map(int, input.readline().split())
    actors = map(lambda x: x - 1, actors)
    movies.append(evaluate(actors))

for i in xrange(N):
    sure_fav = True
    sure_not = False

    for j in xrange(N):
        if i != j:
            if movies[i][0] < movies[j][1]:
                sure_fav = False
            if movies[i][1] < movies[j][0]:
                sure_not = True
        
    output.write('0' if sure_fav else ('1' if sure_not else '2'))
    output.write('\n')