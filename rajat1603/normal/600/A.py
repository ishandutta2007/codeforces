arr = raw_input()
newarr1 = arr.split(',')
newarr2 = [temp.split(';') for temp in newarr1]
result1 = []
result2 = []
for x in newarr2:
    for y in x:
        try:
            faaltu = int(y)
            if len(y) > 1 and y[0] == '0':
                result2.append(y)
            else:
                result1.append(y)
        except:
            result2.append(y)
if len(result1) >= 1:
    print '"' + ",".join(result1) + '"'
else:
    print '-'

if len(result2) >= 1:
    print '"' + ",".join(result2) + '"'
else:
    print '-'