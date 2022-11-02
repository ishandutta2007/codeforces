right,left=0,1
d={}
for _ in [0]*int(input()):
    letter,number=input().split()
    if letter=="L":
        left-=1
        d[int(number)]=left
    elif letter=='R':
        right+=1
        d[int(number)]=right
    else:
        print(min(d[int(number)]-left,right-d[int(number)]))