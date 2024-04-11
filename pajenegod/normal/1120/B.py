import sys
range = xrange
input = raw_input

n = int(input())
a = input()
b = input()

A = [int(c) for c in a]
A_copy = A[:]
B = [int(c) for c in b]


move_count = 0
extreme = [0]*n
for i in range(n):
    # Fix what previous digits need
    diff = extreme[i]
    current = A_copy[i]

    if diff>0 and current>0:
        now = min(diff,current)
        diff -= now
        current -= now
    
    if diff<0 and current<9:
        now = min(-diff,9-current)
        diff -= -now
        current -= -now
        

    goal = B[i]
    # The next node needs to take care of the difference
    nesta = -diff - (goal - current)
    move_count += abs(nesta)
    
    if i+1==n:
        if nesta!=0:
            print -1
            sys.exit()
    else:
        extreme[i+1] = nesta



moves = []
Q = []
for i in reversed(range(n)):
    Q.append((i,B[i]))

big = 10**5
while Q and len(moves)<big:
    ind, goal_val = Q.pop()
    
    val = A[ind]
    if val==goal_val:continue

    if val<goal_val:
        if ind+1==n:
            print -1
            sys.exit()
        if A[ind+1]==9:
            Q.append((ind,goal_val))
            Q.append((ind+1,8))
        else:
            moves.append((ind,1))
            A[ind] += 1
            A[ind+1] += 1
            Q.append((ind,goal_val))
        continue
    # val>goal_val

    if ind+1==n:
        print -1
        sys.exit()
    if A[ind+1]==0:
        Q.append((ind,goal_val))
        Q.append((ind+1,1))
    else:
        moves.append((ind,-1))
        A[ind] -= 1
        A[ind+1] -= 1
        Q.append((ind,goal_val))


print move_count
print '\n'.join(str(a+1)+" "+str(b) for a,b in moves[:10**5])