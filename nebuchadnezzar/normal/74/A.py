import sys
 
#file=open("data.in")
#file=sys.stdin

n=int(sys.stdin.readline())

q=-30000
nik="0"

for i in xrange(n):
    a=sys.stdin.readline().split()
    plus=int(a[1])
    minus=int(a[2])
    ai=int(a[3])
    bi=int(a[4])
    ci=int(a[5])
    di=int(a[6])
    ei=int(a[7])
    if (q<plus*100-minus*50+ai+bi+ci+di+ei):
        q=plus*100-minus*50+ai+bi+ci+di+ei
        nik=a[0]

print(nik)