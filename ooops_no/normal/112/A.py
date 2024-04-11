a=input().lower()
b=input().lower()
c=0
while True:
 try:
  if a[c]==b[c]:
   c+=1
  else:
   if a[c]<b[c]:
    print(-1)
    break
   else:
    print(1)
    break
 except IndexError:
  print(0)
  break