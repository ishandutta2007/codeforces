for _ in range(int(input())):
    x=bin(int(input()))
    b=x.count("1")
    print(1 << b)