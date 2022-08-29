N = int(raw_input())
groups = map(int, raw_input().split(' '))
freq = [0] * 5

for g in groups:
    freq[g] += 1

answer = freq[4]
freq[4] = 0
take = min(freq[3], freq[1])
answer += take
freq[3] -= take
freq[1] -= take

if freq[3] > 0:
    answer += freq[3]
    freq[3] = 0

take = freq[2] // 2
answer += take
freq[2] -= 2 * take
assert freq[2] <= 1

if freq[2] > 0:
    take = min(freq[1], 2)
    freq[1] -= take
    freq[2] = 0
    answer += 1

answer += (freq[1] + 3) // 4
freq[1] = 0
assert freq[1] == 0 and freq[2] == 0 and freq[3] == 0 and freq[4] == 0
print answer