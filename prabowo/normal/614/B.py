n = int(input())
ls = list(input().split())

ans = 0
satu = True
lead = '1'
for s in ls : 
	if (s == '1' + '0' * (len(s) - 1)) : ans += len(s) - 1
	elif (s == '0') : print(0); exit(0)
	else : lead = s
	
	
print(lead, end = "")
print ('0' * ans)