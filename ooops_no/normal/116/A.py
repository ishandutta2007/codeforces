g=[]
a=0
for i in range(int(input())):
    s=[int(i) for i in input().split()]
    a+=s[1]-s[0]
    g+=[a]
print(max(g))