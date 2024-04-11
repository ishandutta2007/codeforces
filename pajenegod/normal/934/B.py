import sys
input = raw_input
range = xrange

loops = [1,0,0,0,1,0,1,0,2,1]

k = int(input())
maxipos = 18*2
if k>maxipos:
    print -1
    sys.exit()

out = []
while k>0:
    if k>=2:
        out.append('8')
        k-=2
    else:
        out.append('6')
        k-=1
if len(out)==0:
    out.append('1')

print ''.join(out)