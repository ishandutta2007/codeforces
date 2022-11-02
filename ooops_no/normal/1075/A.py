x=int(input())
a,b=map(int,input().split())
if b>=a:
    white=b-1
else:
    white=(a-b)+(b-1)
if a>=b:
    black=x-b
else:
    black=(b-a)+(x-b)
if black<white:
    print("Black")
else:
    print("White")