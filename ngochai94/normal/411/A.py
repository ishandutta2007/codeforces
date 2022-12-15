word=raw_input()
n=0
upper='ABCDEFGHIJKLMNOPQRSTUVWXYZ'
lower='abcdefghijklmnopqrstuvwxyz'
spec='0123456789'
while True:
    if len(word)<5:
        print 'Too weak'
        break
    for i in word:
        if i in lower:
            n+=1
    if n==0:
        print 'Too weak'
        break
    n=0
    for i in word:
        if i in upper:
            n+=1
    if n==0:
        print 'Too weak'
        break
    n=0
    for i in word:
        if i in spec:
            n+=1
    if n==0: 
        print 'Too weak'
        break
    print 'Correct'
    break