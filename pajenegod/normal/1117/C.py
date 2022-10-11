import sys
range = xrange
input = raw_input

x1,y1 = [int(x) for x in input().split()]
x2,y2 = [int(x) for x in input().split()]


n = int(input())
s = input()

cumsum = [[0]*(n+1) for _ in range(4)]
mapper = {'U':0,'D':1,'L':2,'R':3}
for i in range(1,n+1):
    numb = mapper[s[i-1]]
    cumsum[0][i] = cumsum[0][i-1]
    cumsum[1][i] = cumsum[1][i-1]
    cumsum[2][i] = cumsum[2][i-1]
    cumsum[3][i] = cumsum[3][i-1]
    
    cumsum[numb][i] += 1

a = 0
b = 2*10**18
while a!=b:
    c = (a+b)//2
    
    counter = [0]*4
    whole = c//n
    left = c%n
    for i in range(4):
        counter[i] += cumsum[i][-1]*whole
        counter[i] += cumsum[i][left]

    X,Y = x1+counter[3]-counter[2],y1-counter[1]+counter[0]
    if abs(X-x2)+abs(Y-y2)<=c:
        b = c
    else:
        a = c+1

if a==2*10**18:
    print -1
else:
    print a