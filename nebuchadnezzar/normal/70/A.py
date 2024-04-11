import sys

#file=open("data.in")
#file=sys.stdin

n=int(sys.stdin.readline())
if (n==0):
    print('1')
else:
    print((3**(n-1))%(10**6+3))