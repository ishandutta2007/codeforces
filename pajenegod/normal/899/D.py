n = int(input())

def spades(n):
    i=0
    while 10**i<=n:i+=1
    upper = 10**i
    if n>=upper//2:
        #n>=50000
        R = i
        #c = int(str(n)[0])
#        choices_of_first = min(c-4)
#        choices_of_rest = 10**(i-1)
#        total = 2*choices_of_first*choices_of_rest
#   #     if c==9:
#   #         total-=1
#        return total
    else:
        #n<=49999
        R = i-1
#        c = int(str(n)[0])
#        if R==0:
#            
#        else:
#            N=c+1
#            total=N*(N+1)//2*5*10**(R-1)
#        total
#
#        print(total-1)
    base = (10**R)-1
    count = 0
    if base==0:
        for i in range(1,n+1):
            for j in range(1,n+1):
                if i!=j:
                    count += 1

    else:
        count = 0
        for j in range(10):
            goal = j*(base+1)+base
            l = max(1,goal-n)
            r = min(goal-1,n)
            if r-l+1>=0:
                count += r-l+1

            #i<goal
            #goal-n<=i
            #1<=i
            #i<=n
    #        for i in range(1,n+1):
    #            if 0<goal-i<=n:
    #                print("found",i,goal-i)
    #                count+=1
    print(count//2) 
spades(n)