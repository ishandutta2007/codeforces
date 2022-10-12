s = input()

m = int(input())
for i in range(m) :
	l, r, k = map(int, input().split())
	
	l -= 1
	r -= 1
	k %= (r - l + 1)
		
	s = s[:l] + s[r-k+1:r+1] + s[l:r+1-k] + s[r+1:]	
	
print(s)