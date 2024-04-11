import sys
import math
range = xrange
input = raw_input

n,r = [int(x) for x in input().split()]



#ang = 2*pi/360

#R+r
#
#R
#r+R
#sqrt(R2+(r+R)2)
#
#tan(R/(r+R))=ang/2
#R/(r+R)=arctan(ang/2)
#
#R = x*(r+R)
#(1-x)*R=x*r
#R = x*r/(1-x)

#R/(r+R)


ang = 2*math.pi/n

x = math.sin(ang/2)

R = x*r/(1-x)

print '%.100f' % R