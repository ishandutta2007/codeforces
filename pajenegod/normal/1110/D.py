import sys
from collections import defaultdict as di
input = raw_input
range = xrange

n,m = [int(x) for x in input().split()]
A = [int(x) for x in sys.stdin.read().split()]

count = di(int)
for a in A:
    count[a]+=1

B = sorted(set(A))
counter = [count[b] for b in B]
counter.append(0)
counter.append(0)

mem = {}

old_arr = [0]*9
for i in reversed(range(len(B))):
    new_arr = [0]*9
    for prev in range(3):
        for prevprev in range(3):
            a,b,c = counter[i-2]-prevprev-prev,counter[i-1]-prev,counter[i]
            if i>=2 and B[i-2]+2==B[i]:
                left = max(0,min(a,b,c,2))
            else:
                left = 0
            
            besta = 0
            for cons in range(left+1):
                score = cons
                score += (a-cons)//3
                if i==len(B)-1:
                    score += (b-cons)//3
                    score += (c-cons)//3
                    besta = max(besta, score) 
                else:
                    besta = max(besta, score + old_arr[prev*3+cons])


            new_arr[prevprev*3+prev] = besta
    old_arr,new_arr = new_arr,old_arr
print(old_arr[0])