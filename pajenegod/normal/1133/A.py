import sys
range = xrange
input = raw_input

h1,m1 = [int(x) for x in input().split(':')]
h2,m2 = [int(x) for x in input().split(':')]

t = (h1+h2)*60 + (m1+m2)
t//=2
h3 = t//60
m3 = t%60

print ('%2i:%2i' %(h3,m3)).replace(" ","0")