x=raw_input().split('+')
a=len(x[0])
y=x[1].split('=')
b=len(y[0])
c=len(y[1])
while True:
    if a+b==c:
        print a*'|'+'+'+b*'|'+'='+c*'|'
        break
    if a+b+2==c:
        print (a+1)*'|'+'+'+b*'|'+'='+(c-1)*'|'
        break
    if a+b-2==c:
        if a>1:
            print (a-1)*'|'+'+'+b*'|'+'='+(c+1)*'|'
            break
        else:
            print a*'|'+'+'+(b-1)*'|'+'='+(c+1)*'|'
            break
    print 'Impossible'
    break