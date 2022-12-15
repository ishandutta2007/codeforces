s=raw_input()[1:-1].split(', ')
a=set()
for i in s:
    if i!='':
        a.add(i)
print len(a)