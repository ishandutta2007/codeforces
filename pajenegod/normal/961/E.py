import sys
range = xrange
input = raw_input

class seg:
    def __init__(self,n):
        m = 1
        while m<n:m*=2
        self.m = m
        self.n = n
        self.data=[0]*(n+m)
    def add(self,ind):
        ind += self.m
        while ind>0:
            self.data[ind]+=1
            ind//=2
    def count(self,r):
        summa = 0
        l = self.m
        r += self.m
        while l<r:
            if l%2==1:
                summa += self.data[l]
                l+=1
            if r%2==1:
                r-=1
                summa += self.data[r]
            l//=2
            r//=2
        return summa

n = int(input())
A = [min(int(x)-1,n-1) for x in input().split()]

B = [(A[i],i) for i in range(n)]
B.sort(reverse=True)

counter = 0
Q = [min(A[sea]+1,sea) for sea in range(n)]

duper = seg(n)

j = 0
for i in reversed(range(n)):
    while j<n and  B[j][0]>=i:
        duper.add(B[j][1])
        j+=1
    
    R = Q[i]
    #val = i
    counter += duper.count(R)



# R,val, #x<R: A[x]>=val 
#for sea in range(n):
#    Q[sea].append((min(A[sea-1]+1,sea),sea))

#for R,val in Q:
#    for epi in range(R):
#        if A[epi]>=val:
#            counter+=1
    #for epi in range(min(A[sea-1]+1,sea)):
    #    if sea<=A[epi]:
    #        counter +=1

print(counter)