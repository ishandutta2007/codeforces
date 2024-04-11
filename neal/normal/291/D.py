N, K = map(int, raw_input().split())
assert 2**K >= N - 1

values = [1] * (N + 1)
values[N] = 0

while values[1] < N - 1:
    add = []

    for i in xrange(1, N + 1):
        need = (N - i) - values[i]
        add.append(max(N - need, i))
        values[i] += values[add[-1]]

    print ' '.join(map(str, add))
    K -= 1

for i in xrange(1, N + 1):
    assert values[i] == N - i

while K > 0:
    print ' '.join(map(str, [N] * N))
    K -= 1