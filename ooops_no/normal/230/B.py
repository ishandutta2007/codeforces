N=1000000
a=[1]*N
a[0]=a[1]=0
s=set()
for i,x in enumerate(a):
  if x:
    s.add(i*i)
    for j in range(i+i,N,i):
      a[j] = 0
input()
for x in map(int,input().split(" ")):
  print("YES" if x in s else "NO")