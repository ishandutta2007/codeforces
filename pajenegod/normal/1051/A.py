import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    s = [c for c in input()]
    n = len(s)

    numbs = '0123456789'
    alf = 'abcdefghijklmnopqrstuvwxyz'
    Alf = 'abcdefghijklmnopqrstuvwxyz'.upper()

    choice = [[False]*n for _ in range(3)]
    for i in range(n):
        if s[i] in numbs:
            choice[0][i] = True
        if s[i] in alf:
            choice[1][i] = True
        if s[i] in Alf:
            choice[2][i] = True

    best_int = 10000000
    best_i = 0
    best_j = 0
    
    count00 = 0
    count01 = 0
    count02 = 0
    for i in range(n):
        if i>0:
            count00 += choice[0][i-1]
            count01 += choice[1][i-1]
            count02 += choice[2][i-1]
        count10 = 0
        count11 = 0
        count12 = 0
        for j in reversed(range(i,n+1)):
            if j<n:
                count10 += choice[0][j]
                count11 += choice[1][j]
                count12 += choice[2][j]
            #good = sum(choice[0][:i])+sum(choice[1][:i])+sum(choice[2][:i])
            #good += sum(choice[0][j:])+sum(choice[1][j:])+sum(choice[2][j:])
            
            #assert(good == count0 + count1)
            good = ((count00+count10)>0)
            good += ((count01+count11)>0)
            good += ((count02+count12)>0)
            if good + j-i>=3 and j-i<best_int:
                best_int = j-i
                best_i = i
                best_j = j
    missing0 = (sum(choice[0][:best_i])+sum(choice[0][best_j:]))==0
    missing1 = (sum(choice[1][:best_i])+sum(choice[1][best_j:]))==0
    missing2 = (sum(choice[2][:best_i])+sum(choice[2][best_j:]))==0

    for i in range(best_i,best_i+3):
        if missing0:
            s[i]='0'
            missing0=False
        elif missing1:
            s[i]='a'
            missing1=False
        elif missing2:
            s[i]='A'
            missing2=False
    
    print ''.join(s)