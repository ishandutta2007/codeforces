import sys
range = xrange
input = sys.stdin.readline

# Resubmitting old code to compare times

class maxseg:
    def __init__(self,data):
        n = len(data)
        m = 1
        while m<n:m*=2
        self.n = n
        self.m = m

        self.data = [0]*(m+m)

        for i in range(n):
            self.data[m+i]=data[i]
        for i in reversed(range(m)):
            self.data[i]=max(self.data[2*i],self.data[2*i+1])

    def setter(self,i,val):
        i += self.m
        self.data[i]=val
        i//=2
        while i>0:
            a = max(self.data[2*i],self.data[2*i+1])
            if self.data[i]==a:break
            self.data[i]=a
            i//=2

    # First time A[i]>=val
    def first_time(self,l,r,val):
        l+=self.m
        r+=self.m

        segs1 = []
        segs2 = []
        while l<r:
            if l%2==1:
                segs1.append(l)
                l+=1
            if r%2==1:
                r-=1
                segs2.append(r)
            l//=2
            r//=2
        segs = segs1+segs2[::-1]
        goal = None
        for seg in segs:
            if self.data[seg]>=val:
                while seg<self.m:
                    if self.data[2*seg]>=val:
                        seg *= 2
                    else:
                        seg = 2*seg+1
                goal = seg-self.m
                break
        return goal

class sumseg:
    def __init__(self,data):
        n = len(data)
        m = 1
        while m<n:m*=2
        self.n = n
        self.m = m
        self.data = [0]*(m+m)
        for i in range(n):
            self.data[m+i]=data[i]
        for i in reversed(range(m)):
            self.data[i]=self.data[2*i]+self.data[2*i+1]

    def setter(self,i,val):
        i += self.m
        diff = val-self.data[i]
        while i>0:
            self.data[i]+=diff
            i//=2
    def summa(self,l,r):
        l+=self.m
        r+=self.m
        s = 0
        while l<r:
            if l%2==1:
                s += self.data[l]
                l+=1
            if r%2==1:
                r-=1
                s += self.data[r]
            l//=2
            r//=2
        return s


n,q = [int(x) for x in input().split()]

A = [int(x) for x in input().split()]

maxA = maxseg(A)
sumA = sumseg(A)

out = []
for _ in range(q):
    p,x = [int(x) for x in input().split()]
    p-=1

    A[p]=x
    maxA.setter(p,x)
    sumA.setter(p,x)

    i=0
    lista = []
    while i!=None:
        s = sumA.summa(0,i)
        if A[i]==s:
            lista.append(i)
            break
        s += A[i]
        i = maxA.first_time(i+1,n,s)
    if len(lista)==0:
        out.append('-1')
    else:
        out.append(' '.join(str(x+1) for x in lista))
print '\n'.join(out)