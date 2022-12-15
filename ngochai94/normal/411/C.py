a=raw_input()
t1=a.split()
for i in range(2):
    t1[i]=int(t1[i])
    
b=raw_input()
t2=b.split()
for i in range(2):
    t2[i]=int(t2[i])
c=raw_input()
t3=c.split()
for i in range(2):
    t3[i]=int(t3[i])
d=raw_input()
t4=d.split()
for i in range(2):
    t4[i]=int(t4[i])

t11=[t1[0],t2[1]]
t12=[t2[0],t1[1]]
t21=[t3[0],t4[1]]
t22=[t4[0],t3[1]]
def win(x,y):
    if x[1]>y[0] and x[0]>y[1]:
        return True
    return False
    
if (win(t11,t21) and win(t11,t22)) or (win(t12,t21) and win(t12,t22)):
    print 'Team 1'
    
elif (win(t21,t11) and win(t21,t12)) or (win(t22,t11) and win(t22,t12)) or (win(t21,t11) and win(t22,t12)) or (win(t22,t11) and win(t21,t12)):
    print 'Team 2'
else:
    print 'Draw'