import sys
range = xrange
input = raw_input

h,m = [int(x) for x in input().split()] 
H,D,C,N = [int(x) for x in input().split()]

now = ((H+N-1)//N)*C

while h<20:
    H+=D
    m+=1
    if m==60:
        m=0
        h+=1
later = ((H+N-1)//N)*C*0.8
print("{0:.15f}".format(min(now,later)))