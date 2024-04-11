a = input()

cnt = sum(int(i) for i in a)
while cnt % 4 != 0:
    a = str(int(a) + 1)
    cnt = sum(int(i) for i in a)
	
print(a)