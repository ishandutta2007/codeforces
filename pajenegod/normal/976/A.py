import sys
range = xrange
input = raw_input

n = int(input())
s = int(input(),2)
if s==0:
    print 0
    sys.exit()

zeros = 0
m = 1
while m<=n:
    if (s//(2**(m-1)))%2==0:
        zeros += 1
    m+=1
numb = 2**zeros
print bin(numb)[2:]