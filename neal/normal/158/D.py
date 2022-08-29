N = int(raw_input())
value = map(int, raw_input().split(' '))
assert len(value) == N

sides = 3
best = -10**9

while sides <= N:
    if N % sides == 0:
        jump = N // sides

        for start in xrange(jump):
            i = start
            accum = 0

            while i < N:
                accum += value[i]
                i += jump

            best = max(best, accum)

    sides += 1

print best