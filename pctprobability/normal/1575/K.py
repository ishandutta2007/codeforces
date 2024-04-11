mod=10**9+7
N,M,K,R,C=map(int,input().split())
AX,AY,BX,BY=map(int,input().split())
if AX>BX:
  AX,BX=BX,AX
if AY>BY:
  AY,BY=BY,AY
Z=0
if AX+R>BX and AY+C>BY:
  Z=(AX+R-BX)*(AY+C-BY)
V=N*M-R*C*2+Z
if (AX,AY)==(BX,BY):
  Z=0
print(pow(K,V+R*C-Z,mod))