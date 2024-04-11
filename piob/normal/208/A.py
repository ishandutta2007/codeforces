
a = raw_input()

a = a.replace('WUB', ' ')
a = a.split()

a = [x for x in a if x != ' ']

print ' '.join(a)