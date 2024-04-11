MAX_CNT = 6
X = int(input())
N = len(str(X))

NUMBERS = [0] * (N + 2)
CUTOFFS = [0] * (N + 2)

for d in range(1, N + 2):
    NUMBERS[d] = 10 * NUMBERS[d - 1] + 1
    CUTOFFS[d] = 10**(d - 1) * 50 // 81 + 15

INF = 10**9
save = [{} for d in range(N + 2)]

def recurse(value, d):
    if d == 0:
        return 0 if value == 0 else INF

    if value in save[d]:
        return save[d][value]

    ans = INF

    for cnt in range(0, MAX_CNT + 1):
        nvalue = abs(value - cnt * NUMBERS[d])

        if nvalue <= CUTOFFS[d]:
            ans = min(ans, cnt * d + recurse(nvalue, d - 1))

    save[d][value] = ans
    return ans

print(recurse(X, N + 1))