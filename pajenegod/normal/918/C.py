range = xrange
input = raw_input

s = input()
n = len(s)

combs = 0
for i in range(n):
    leftmin = 0
    leftmax = 0
    for j in range(i,n):
        if s[j]=='(':
            leftmin += 1
            leftmax += 1
        elif s[j]==')':
            if leftmin>0:
                leftmin -=1
            else:
                leftmin +=1
            leftmax -=1
        elif s[j]=='?':
            leftmax+=1
            if leftmin>0:
                leftmin-=1
            else:
                leftmin+=1
        
       
        if leftmax<0 or leftmin>leftmax:
            break

        if leftmin==0:
            combs+=1
print combs