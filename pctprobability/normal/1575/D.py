S=input()
ANS=0
for i in range(0,10**8,25):
  T=str(i)
  if len(T)>len(S):
    continue
  if len(T)<len(S):
    continue
  X=-1
  A=1
  for j in range(len(S)):
    if S[j]=='_':
      continue
    if S[j]=='X':
      if X==-1:
        X=int(T[j])
      else:
        if int(T[j])!=X:
          A=0
          break
    else:
      if S[j]!=T[j]:
        A=0
        break
  ANS+=A
print(ANS)