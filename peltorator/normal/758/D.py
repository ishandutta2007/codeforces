n = int(raw_input())
s = raw_input()[::-1]
l = len(s)
dp = [[int('1' + '0' * 66) for x in xrange(66)] for y in xrange(66)]
dp[0][0] = 0
for i in range(l):
	for j in range(i + 1):
		for k in range(i, l):
			nint = int(s[i:k+1][::-1])
			if nint >= n:
				break
			if s[k] == '0' and k > i:
				continue
			dp[k + 1][j + 1] = min(dp[k + 1][j + 1], dp[i][j] + nint * (n ** j))

print min(dp[l])