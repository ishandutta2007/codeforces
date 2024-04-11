p, d = map(int, raw_input().strip().split())
length = len(str(p))
#print length
l = 0
r = 20
while(r - l > 1):
    m = (r + l) / 2
    #print m,  ":"
    if(m == length):
        #print "m == length"
        if(str(p) == "9" * m):
            l = m
            #print "l"
        else:
            r = m
            #print "r"
    elif(m > length):
        #print "m > length"
        r = m
    else:
        #print "m < length"
        new_num = int(str(p)[: (length - m)] + "9" * m)
        #print new_num
        new_num -= int("1" + "0" * m)
        #print new_num
        if(new_num + d >= p):
            l = m
            #print "l"
        else:
            r = m
            #print "r"

#print l
if(l == length):
    new_num = "9" * l
elif(l == 0):
    new_num = p
else:
    new_num = int(str(p)[: (length - l)] + "9" * l)
    if(new_num > p):
        #print new_num
        new_num -= int("1" + "0" * l)

    #print new_num
            
print new_num