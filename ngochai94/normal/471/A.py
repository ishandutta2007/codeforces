s=map(int,raw_input().split())
can=False
for i in s:
    if s.count(i)>=4:
        can=True
        for j in range(4):
            s.remove(i)
        break
if can:
    if s[0]!=s[1]:
        print 'Bear'
    else:
        print 'Elephant'
else:
    print 'Alien'