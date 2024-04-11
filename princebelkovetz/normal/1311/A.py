for _ in range(int(input())):
    a,b=map(int,input().split())
    if a==b:
        print(0)
    elif ((a>b) and (b%2!=a%2)) or ((a<b) and (b%2==a%2)):
        print(2)
    else:
        print(1)