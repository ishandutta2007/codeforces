import sys
n,m,c = [int(x) for x in input().split()]
l = 0
r = 0

smalldata = [c+1]*n
largedata = [-1]*n
small = c//2
large = c - small

for i in range(m):
    num = int(input())
    if num<=small: # if num is small
        #print("small")
        ind = 0
        while smalldata[ind]<=num:
            ind += 1
        smalldata[ind] = num
        l = 1
        while l<n and smalldata[l] != c+1 and smalldata[l-1]<=smalldata[l]:
            l+=1
    else: # if num is large
        #print("large")
        ind = n-1
        while largedata[ind]>=num:
            ind -= 1
        largedata[ind] = num
        r = 1
        while r<n and largedata[-r-1]!=-1 and largedata[-r]>=largedata[-r-1]:
            r+=1
    print(ind+1)
    sys.stdout.flush()
    if l+r>=n:
        #print("WON")
        break