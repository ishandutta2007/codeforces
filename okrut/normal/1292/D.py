
import copy

M = 5003
Primes = []
Rob = [0] * M
for x in range(2,M):
	if Rob[x]==0:
		Primes.append(x)
	y = x+x
	while y<M:
		Rob[y]+=1
		y+=x

P = len(Primes)


n = int(input())
Cnt = [0] * M
for a in input().split():
	Cnt[int(a)] +=1


PF = []
PF.append( [0] * P)
s = 0

res = 0
for k in range(1, M):
	PF.append(copy.copy(PF[-1]))
	
	x = k
	for p in range(P):
		while x % Primes[p] ==0:
			PF[k][p]+=1
			x/=Primes[p]
			s+=1

	res += Cnt[k] * s
	

for i in range(M):
	while (len(PF[i])>0 and PF[i][-1]==0):
		PF[i].pop()
	

BPD = [ len(PF[i]) for i in range(M) ]


branched = 0
frequency = [0] * (P+1)
while ( max(BPD) > 0):
	
	# Find the best prime divisors:
	
	for i in range(P+1): frequency[i] = 0
	
	for i in range(M): frequency[BPD[i]] += Cnt[i]
	
	m = max(frequency)
	pr = frequency.index(m)
	
	if pr==0:
		break
	
	for i in range(M):
		if BPD[i]!=pr:
			branched += Cnt[i]
			Cnt[i] = 0
			BPD[i] = 0
	
	if branched * 2 >= n:
		break
	
	res += 2* branched - n
	
	for i in range(M):
		if (BPD[i]==0): continue
		
		if (len(PF[i])>0):
			PF[i][-1]-=1
		while (len(PF[i])>0 and PF[i][-1]==0):
			PF[i].pop()
		BPD[i] = len(PF[i])

print(res)