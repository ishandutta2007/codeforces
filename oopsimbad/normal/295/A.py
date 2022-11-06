n,m,k = map(int, input().split())
arr = [int(x) for x in input().split()]
psum = [0]*(n+1)
psum2 = [0]*(m+1)
q = []
for _ in range(m):
  q.append([int(x) for x in input().split()])


while k > 0:
    k -= 1
    a,b = map(int, input().split())
    psum2[a-1] += 1
    psum2[b] -= 1

for i in range(m):
    psum2[i+1] += psum2[i]
    psum[q[i][0]-1] += psum2[i]*q[i][2]
    psum[q[i][1]] -= psum2[i]*q[i][2]

for i in range(n):
    psum[i+1] += psum[i]
    print(psum[i]+arr[i],end=' ')