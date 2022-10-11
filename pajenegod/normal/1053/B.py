import sys
#range = xrange
input = sys.stdin.readline

n = int(input())
A = [int(x) for x in input().split()]

B = [bin(a).count('1') for a in A]

Bcumsum = [0]
for b in B:
    Bcumsum.append((Bcumsum[-1]+b)%2)

count0 = [0]*(n+1)
for i in reversed(range(n)):
    count0[i] = count0[i+1] + (Bcumsum[i+1]==0)

numb = 65

sol = 0
for i in range(n):
    mini = B[i]
    maxi = mini
    for j in range(i+1,min(i+1+numb,n)):
        
        if mini<=B[j]<=maxi:
            if (mini+B[j])%2==0:
                mini = 0
            else:
                mini = 1
        else:
            if B[j]<mini:
                mini = mini-B[j]
            else:
                mini = B[j]-maxi
        
        #mini = min(abs(x-B[j]) for x in range(mini,maxi+1,2))
        
        maxi = B[j] + maxi

        if mini==0:
            sol += 1
    
    if i+1+numb<n:
        count = count0[i+1+numb]
        if (mini+Bcumsum[i+1+numb])%2==1:
            count = n-(i+1+numb) - count
        sol += count

print(sol)