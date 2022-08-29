MOD = 1000000007

N, M = map(int, raw_input().split(' '))
names = [""] * N

for i in xrange(N):
    names[i] = raw_input()

answer = 1

for j in xrange(M):
    letters = []

    for i in xrange(N):
        letters.append(names[i][j])

    answer *= len(set(letters))
    answer %= MOD

print answer