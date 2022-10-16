a = input().lower();
a = a.replace('a','').replace('e','').replace('u','').replace('o','').replace('i','').replace('y','')
print(a.replace('','.')[:len(a)*2])