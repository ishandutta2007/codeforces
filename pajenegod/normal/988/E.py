import sys
range = xrange
input = raw_input

x = int(input())

xs = str(x)
if xs.count('0')<2 and \
  (xs.count('2') + xs.count('5')) < 2 and \
  (xs.count('5') + xs.count('0')) < 2 and \
  (xs.count('7') + xs.count('5')) < 2:
    print '-1'
    sys.exit()

def f(x,d):
    sx = str(x)
    n = len(sx)
    if sx[-2:] in ('00','25','50','75'):
        return 0
    
    if d<0: return 100

    besta = 100
    for i in range(len(sx)-1):
        if sx[i] in '0257':
            if sx[i] in '50':
                inter = [n-2,n-1]
            else:
                inter = [n-2]
            for j in inter:
                if i>=j:continue
                if (i!=0 or sx[i+1]!='0'):
                    besta = min(besta, j-i + f(int(''.join((sx[:i],sx[i+1:j+1],sx[i],sx[j+1:]))), d-1))
        
        if i!=0 and sx[i]!='0' and sx[i-1]=='0':
            j = i-1
            while sx[j] == '0':
                j -= 1
            i,j = j+1,i
            besta = min(besta, j-i + f(int(''.join((sx[:i]+sx[j]+sx[i:j],sx[j+1:]))), d-1))

    return besta

best = f(x,3)


if best >= 100:
    print -1
else:
    print best