n = int (input ())
p = input ().split ()

fail = False

for i in range (n) :
	s = list (input ())
	cnt = s.count ('a') + s.count ('e') + s.count ('i') + s.count ('o') + s.count ('u') + s.count ('y')
	if cnt != int (p[i]) :
		fail = True
		
if fail : 
	print ("NO")
else :
	print ("YES")