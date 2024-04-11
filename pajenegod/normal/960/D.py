import sys
range = xrange
input = raw_input

out = []

maxlevel = 61
shifts = [0]*maxlevel
mods = [1] + [2**(i-1) for i in range(1,maxlevel)]
q = int(input())
inp = [int(x) for line in sys.stdin for x in line.split()]
ii = 0
for _ in range(q):
    T = inp[ii]
    ii+=1
    if T==1:
        X = inp[ii]
        ii+=1
        
        level = 0
        while X>0:
            X//=2
            level+=1

        K = inp[ii]%mods[level]
        ii+=1
        shifts[level]+=K
        shifts[level]%=mods[level]

    elif T==2:
        X = inp[ii]
        ii+=1

        level = 0
        while X>0:
            X//=2
            level+=1
        
        K = inp[ii]%mods[level]
        ii+=1
         
        for i in range(level,maxlevel):
            shifts[i]+=K
            shifts[i]%=mods[i]
            if i+1<maxlevel:
                K*=2
    else:
        X = inp[ii]
        ii+=1
        Y = X
        level = 0
        while Y>0:
            Y//=2
            level+=1

        basic = mods[level]
        shift = -shifts[level]
        X = basic+((-shift+X-basic)%basic)

        nodes = []
        while X>0:
            nodes.append(X)
            X//=2
        #print(nodes)
        #print(shifts)
        #print(mods)
        outs = []
        for i in range(level):
            basic = mods[level-i]
            shift = shifts[level-i]
            node = nodes[i]
            outs.append(basic+((-shift+node-basic)%basic))
        
        print ' '.join([str(AB) for AB in outs])