t = int(input())

for q in range(t):
	
	n, x, y = map(int, input().split())
	Bob = list(map(int, input().split()))
	
	Cnt = [ [0, i] for i in range(n+1) ] 
	Ans = [ -1] * n
	Occ = [ [] for i in range(n+1) ]
		
	for i in range(n):
		Bob[i]-=1
		Cnt[Bob[i]][0] +=1
		Occ[Bob[i]].append(i)
	
	Cnt.sort(reverse = True)
	
	
	#print("\n\nNew test case\n", n, x, y)
	
	#print("Cnt ", Cnt)
	
	lvl = Cnt[0][0]
	i=0
	xcpy = x
	while x > 0:
		
		#print("Deleting from ", i)
		
		while x>0 and Cnt[i][0] >= lvl:
			
			#print("Now: ", Cnt[i])
			
			Cnt[i][0]-=1
			col = Cnt[i][1]
			Ans[Occ[col].pop()] = col
			x-=1
		
		
		i+=1
		if i==n or Cnt[i][0] < lvl:
			lvl = Cnt[0][0]
			i = 0
			
	
	Cnt.sort(reverse = True)
	
	#print("Cnt = ", Cnt)
	
	x = xcpy
	
	if Cnt[0][0]*2 - (n-x) > n-y:
		print("NO")
		continue
	
	Pos = []
	Clr = []
	for i in range(n): 
		if Ans[i]==-1:
			Pos.append( [Bob[i], i])
			Clr.append( Bob[i])
	
	m = len(Pos)
	
	Pos.sort()
	Clr.sort()
	
	offset = m//2
	
	nocnt = n-y
	nocolor = Cnt[-1][1]
	
	for i in range(m): 
		
		pos = Pos[i][1]
		c = Clr[(offset+i)%m]
		
		if i+nocnt==m:
			Ans[pos] = nocolor
			nocnt-=1
			continue
		
		if Pos[i][0]==c:
			assert(nocnt > 0)
			Ans[pos] = nocolor
			nocnt -=1
		else:
			Ans[pos] = c
	
	
	assert(nocnt==0)
	
	print("YES")
	
	for c in Ans:
		print(c+1, end = ' ')
	print()