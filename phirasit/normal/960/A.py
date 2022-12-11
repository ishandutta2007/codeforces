import re

inp = input().strip()

if re.match(r'^a+b+c*$', inp) and inp.count('c') in [inp.count('a'), inp.count('b')]:
    print ("YES")
else:
    print ("NO")