n=0
l=int(input())
g={}
x=[]
b=0
while n<l:
    a=input()
    if a not in g:
        x+=[a]
        g.update({a:b})
        print('OK')
    else:
        g[a]+=1
        print(str(a)+str(g[a]))
    n+=1