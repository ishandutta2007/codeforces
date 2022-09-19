t=int(input())
for i in range(t):
    n=int(input())
    db=0
    while n%5==0:
        db=db+1
        n=4*n//5
    while n%3==0:
        db=db+1
        n=2*n//3
    while n%2==0:
        db=db+1
        n=n//2
    print (db if n==1 else -1)