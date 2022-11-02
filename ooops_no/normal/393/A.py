s=input()
cntn=max(0,(s.count('n')-1)//2)
cnte=s.count('e')//3
cnti=s.count('i')
cntt=s.count('t')
print(min(cntn,cnte,cnti,cntt))