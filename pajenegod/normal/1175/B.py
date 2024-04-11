z=0
for s in[[1.]]*input():
 t,c=raw_input(),s.pop()
 if'f'<t:s+=c,c*int(t[4:])
 if'e'>t:z+=c;s+=c,
print['OVERFLOW!!!','%.f'%z][z<2**32]