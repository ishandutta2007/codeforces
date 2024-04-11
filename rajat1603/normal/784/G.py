arr = raw_input()
val = eval(arr)
cur = 0
res = ""
for i in range(48):
	res += "+"
val = str(val)
for c in val:
	req = int(c)
	while req > cur:
		res += "+"
		cur += 1
	while req < cur:
		res += "-"
		cur -= 1
	res += "."
print res