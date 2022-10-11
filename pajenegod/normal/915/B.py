n,pos,l,r = [int(x) for x in input().split()]


left_closed = (l==1)
right_closed = (r==n)

moves = 0
while not left_closed or not right_closed:
    if r<pos:
        pos-=1
    elif pos<l:
        pos+=1
    elif pos<r and not right_closed and (left_closed or r-pos<=pos-l):
        pos+=1
    elif pos>l and not left_closed and not (not right_closed and pos==r):
        pos-=1
    #elif not left_closed and pos>l and right_closed:
    #    pos -= 1
    #elif not right_closed and pos<r and left_closed:
    #    pos+=1
    else: 
        if l==pos and not left_closed:
            left_closed = True
        elif r==pos:
            right_closed = True
    moves+=1

print(moves)

#left_closed = (l==1)
#right_closed = (r==n)
#
#moves = 0
#while not left_closed or not right_closed:
#    if pos<=r and not right_closed:
#        moves += r-pos
#        pos  = r
#        right_closed = True
#        moves+=1
#    elif l<=pos and not left_closed:
#        moves += pos-l
#        pos = l
#        left_closed = True
#        moves+=1
#    elif not right_closed and (left_closed or r-pos<=pos-l):
#        moves += r-pos
#        pos = r
#    else:
#        moves += pos-l
#        pos = l