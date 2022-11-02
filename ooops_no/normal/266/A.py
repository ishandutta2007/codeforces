a=int(input())
s=input()
b=0
g=0
while True:
 try:
  if s[b]==s[b+1]:
   g+=1
  b+=1
 except Exception:
  break
print(g)