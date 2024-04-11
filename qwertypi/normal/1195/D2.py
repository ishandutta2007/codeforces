n = int(input())

def cal(X):
    ans = 0
    _len = len(X)
    for i in range(_len):
        ans += int(X[i]) * 100 ** (_len - 1 - i)
    return ans * 11

A = input().split()
def LOL(n):
    if(n == ''):
        return 0
    else:
        return int(n)
cnt = [0 for i in range(11)]
for i in A:
	cnt[len(i)] += 1

ans = 0
for i in A:
	_len = len(i)
	for j in range(1, 1+_len):
		ans += cnt[j] * (2 * LOL(i[:_len - j]) * 100 ** j + cal(i[_len-j:]))
	for j in range(_len+1, 11):
	    ans += cal(i) * cnt[j]
print(ans % 998244353)