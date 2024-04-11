n = int(raw_input())
rd = map(int,raw_input().split())
tmp = sorted([(rd[i],i) for i in range(n)])
rev = {i:tmp[i][1] for i in range(n)}
pos = {tmp[i][1]:i for i in range(n)}
for i in range(n):
 if pos[i]==0:
  print tmp[1][0]-rd[i],
 elif pos[i]==n-1:
  print rd[i]-tmp[n-2][0],
 else:
  print min(abs(rd[i]-tmp[pos[i]-1][0]),abs(rd[i]-tmp[pos[i]+1][0])),
 print max(abs(rd[i]-tmp[0][0]),abs(rd[i]-tmp[n-1][0]))