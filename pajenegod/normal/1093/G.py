import sys
range = xrange
input = raw_input

big = 10**8

class seg:
    def __init__(self,data,n,d):
        m = 1
        while m<n:m*=2
        self.n = n
        self.m = m
        self.mindata = [[big]*(2*m) for _ in range(d)]
        self.maxdata = [[-(big)]*(2*m) for _ in range(d)]
        for j in range(d):
            for i in range(n):
                self.mindata[j][m+i] = data[j+i*d]
                self.maxdata[j][m+i] = data[j+i*d]
            for i in reversed(range(1,m)):
                self.mindata[j][i] = min(self.mindata[j][2*i],self.mindata[j][2*i+1])
                self.maxdata[j][i] = max(self.maxdata[j][2*i],self.maxdata[j][2*i+1])
        self.d = d

    def diff(self,l,r):
        l += self.m
        r += self.m
        maxi = [-big]*self.d
        mini = [big]*self.d
        while l<r:
            if l%2==1:
                for i in range(self.d):
                    maxi[i] = max(maxi[i],self.maxdata[i][l])
                    mini[i] = min(mini[i],self.mindata[i][l])
                l += 1
            if r%2==1:
                r -= 1
                for i in range(self.d):
                    maxi[i] = max(maxi[i],self.maxdata[i][r])
                    mini[i] = min(mini[i],self.mindata[i][r])
            l //= 2
            r //= 2
        return max(maxi[i]-mini[i] for i in range(self.d))
    def set(self,ind,val):
        ind += self.m
        for i in range(self.d):
            self.mindata[i][ind] = val[i]
            self.maxdata[i][ind] = val[i]
        ind //= 2
        old_ind = ind
        for i in range(self.d):
            ind = old_ind
            while ind>0:
                dum = min(self.mindata[i][2*ind],self.mindata[i][2*ind+1])
                if self.mindata[i][ind] != dum:
                    self.mindata[i][ind] = dum
                else:
                    break
                ind //= 2
            ind = old_ind
            while ind>0:
                dum = max(self.maxdata[i][2*ind],self.maxdata[i][2*ind+1])
                if self.maxdata[i][ind] != dum:
                    self.maxdata[i][ind] = dum
                else:
                    break
                ind //= 2


s = sys.stdin.read()
inp = []
numb = 0
sign = 1
 
for i in range(len(s)):
    if s[i]>='0':
        numb = 10*numb + ord(s[i])-48
    else:
        if s[i]=='-':
            sign = -1
        else:
            inp.append(sign*numb)
            numb = 0
            sign = 1
if s[-1]>='0':
    inp.append(sign*numb)
ii = 0

n,k = inp[ii],inp[ii+1]
ii += 2

ways = []
for numb in range(2**(k-1)):
    tmp = []
    ind = 0
    while numb>0:
        if numb%2==1:
            tmp.append(ind)
        numb //= 2
        ind += 1
    ways.append(tmp)

arr = []
for node in range(n):
    total = sum(inp[ii:ii+k])
    for signs in ways:
        arr.append(total - 2*sum(inp[ii+s] for s in signs))
    ii += k

duper = seg(arr,n,2**(k-1))

q = inp[ii]
ii+= 1
out = []
for _ in range(q):
    query = inp[ii]
    ii += 1
    if query==1:
        node = inp[ii]-1
        ii += 1

        total = sum(inp[ii:ii+k])
        vals = [total - 2*sum(inp[ii+s] for s in signs) for signs in ways]

        ii += k
        duper.set(node,vals)
    else:
        l,r  = inp[ii]-1,inp[ii+1]
        ii += 2
        out.append(duper.diff(l,r)) 
print '\n'.join(str(x) for x in out)