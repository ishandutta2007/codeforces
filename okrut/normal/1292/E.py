import sys
t = int(input())

def get():
	ans = ""
	for i in range(n): ans = ans + S[i]
	return ans

def query(pat):
	print("Querying ", pat, file = sys.stderr)
	
	print("? " + pat, flush = True)
	
	A = list(map(int, input().split()))
	for k in A[1:]:
		for i in range(len(pat)):
			S[k-1+i] = pat[i]
	
	return A[0]

def answer():
	
	ans = "! "
	for i in range(n): ans = ans + S[i]
	
	print("Answering ", ans, file = sys.stderr)
	print(ans, flush = True)
	
	input()
	
for q in range(t):
	n = int(input())
	S = ['?'] * n
	
	Ptrns = [ "CO", "CH", "HO", "HC" ]
	
	for pat in Ptrns: query(pat)
	
	
	print("After initial queries ", get(), file = sys.stderr)
	
	known = None
	for i in range(n):
		if S[i]!='?': 
			known = i
			break
	
	if known is None:
		
		if query("OOO")>0:
			
			if query("OOOC")>0: 
				for i in range(n):
					if S[i]=='?': S[i] = 'C'
			else:
				for i in range(n):
					if S[i]=='?': S[i] = 'H'
		
		else:
			
			if query("CCC")>0:
				for i in range(n):
					if S[i]=='?': S[i] = 'O'
			elif query("HHH")>0:
				for i in range(n):
					if S[i]=='?': S[i] = 'O'
			else:
				S[0] = S[1] = 'O'
				if query("OOHH")>0:
					S[2] = S[3] = 'H'
				else:
					S[2] = S[3] = 'C'
		
		answer()
		continue
	
	suf = S[known] + S[known+1]
	while known > 0:
		query(S[known] + suf)
		if S[known-1]=='?':
			for i in range(known):
				S[i] = 'O'
			break
		known-=1
		suf = S[known] + suf
		
	
	r = known
	while r < n and S[r]!='?': r+=1
	
	pref = ""
	for i in range(r): pref = pref + S[i]
	
	while r < n:
		
		print("I have now ", pref, file = sys.stderr)
		
		if S[r-1]=='O':
			query(pref + "O")
			
			if S[r]=='?':
				if r==n-1: # ostatni znak
					if query(pref + "C")==0:
						S[r] = 'H'
				else: # jeszcze nie
					query(pref+ "CC")
					
					if S[r]=='?': S[r] = S[r+1] = 'H'
					
			
		else:
			S[r]=S[r-1]
		
		while r < n and S[r]!='?': 
			pref = pref + S[r]
			r+=1
		
	
	answer()