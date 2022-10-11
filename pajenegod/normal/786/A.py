import sys
#range = xrange
#input = raw_input

n = int(input())
k1,*A = [int(x) for x in input().split()]
k2,*B = [int(x) for x in input().split()]

DPA = [None]*n
DPA[0] = False
counterA = [k1]*n
counterA[0] = -1

DPB = [None]*n
DPB[0] = False
counterB = [k2]*n
counterB[0] = -1


QA = [0]
QB = [0]
while QA or QB:
    while QA:
        i = QA.pop() 
        if DPA[i] == False:
            for b in B:
                if i!=b:
                    if not DPB[i-b]:
                        QB.append((i-b)%n)
                    DPB[i-b] = True
        elif DPA[i]:
            for b in B:
                counterB[i-b] -= 1
                if not counterB[i-b]:
                    #assert(DPB[i-b]==None)
                    DPB[i-b] = False
                    QB.append((i-b)%n)
    
    while QB:
        i = QB.pop() 
        if DPB[i] == False:
            for a in A:
                if i!=a:
                    if not DPA[i-a]:
                        QA.append((i-a)%n)
                    DPA[i-a] = True
        elif DPB[i]:
            for a in A:
                counterA[i-a] -= 1 
                if not counterA[i-a]:
                    #assert(DPA[i-a]==None)
                    DPA[i-a] = False
                    QA.append((i-a)%n)

def f(x):
    if x==None:
        return 'Loop'
    if x:
        return 'Win'
    return 'Lose'

print(*[f(x) for x in DPA[1:]])
print(*[f(x) for x in DPB[1:]])