a=sorted(input())
b=""
for i in a:
 if i=="+":
  continue 
 else:
  b+=i+"+"
b=b[0:-1]
print(b)