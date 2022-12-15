inp=raw_input()
com=inp.split()
for i in range(len(com)):
    com[i]=int(com[i])
for i in range(com[0]):
    x=raw_input()
    y=x.split()
    for i in y:
        com.append(int(i))
cell=[0]*(1+com[2])
time=[0]*com[0]
core=[]
default=()
for i in range(com[1]):
    default+=(-1,)
for i in range(com[0]):
    x=()
    for k in range(com[1]):
        x+=(com[3+com[1]*i+k],)
    core.append(x)
for t in range(com[1]):
    for i in range(com[0]-1):
        for k in range(i+1,com[0]):
            if core[i][t]==core[k][t] and core[i]!=default and core[i][t]!=0:
                cell[core[i][t]]=1
                core[i]=default
                core[k]=default
                time[i]=t+1
                time[k]=t+1
                
    for i in range(com[0]):
        if cell[core[i][t]]==1 and core[i]!=default:
            time[i]=t+1
            core[i]=default
for i in time:
    print i