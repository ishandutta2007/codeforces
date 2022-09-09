import sys

#file=open("data.in")
#file=sys.stdin



n=int(sys.stdin.readline())







for i in xrange(n):
    a=sys.stdin.readline().strip()
    if (len(a)>10):
        q=a[0]+str(len(a)-2)+a[len(a)-1]
        print(q)
    else:
        print(a)