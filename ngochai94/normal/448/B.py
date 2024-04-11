s=raw_input()
t=raw_input()
arr=True
for i in t:
    if t.count(i) > s.count(i):
        arr=False
if not arr:
    print 'need tree'
else:
    if len(s)==len(t):
        print 'array'
    else:
        can=True
        for i in t:
            if s=='':
                can=False
                break
            while s[0]!=i:
                s=s[1:]
                if s=='':
                    can=False
                    break
            s=s[1:]
        if can:
            print 'automaton'
        else:
            print 'both'