import sys
input = raw_input
range = xrange



q = int(input())
for i in range(q):
    xi = int(input())
    if xi==0:
        print 1,1
        continue
    for m in range(2,41700):
        #a = 0
        #b = 100000
        #while b-a>1:
        #    mid = (a+b)//2
        #    if mid**2*(m**2-1)<xi:
        #        a = mid
        #    else:
        #        b = mid
        i = int((float(xi)/(m**2-1))**0.5)
        
        if i == 0:
            print -1
            break
        left = xi-i**2*(m**2-1)
        #a = i*m
        #b = i*m + m

        sidelen=int((left+(i*m)**2)**0.5-1)

  #      while b-a>1:
  #          mid = (a+b)//2
  #          if (mid+1)**2-(i*m)**2<left:
  #              a = mid
  #          else:
  #              b = mid
       # sidelen = i*m
       # extra = 0
       # while left-extra>0:
       #     extra+= 2*sidelen+1
       #     sidelen += 1
       
        extra = (sidelen+1)**2-(i*m)**2
        sidelen += 1
        if left==extra:
            print sidelen,m
            break
    else:
        print -1