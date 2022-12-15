s=map(int,raw_input().split())
s.sort()
b,g,r=s
if r>2*(b+g):
    print b+g
else:
    print (r+g+b)/3