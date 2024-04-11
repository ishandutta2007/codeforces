for _ in range(int(input())):
    n=int(input())
    s=[int(i) for i in input().split()]
    x=True
    for i in range(n-2):
        if s[i] in s[i+2:n]:
            print("YES")
            x=False
            break
    if x:
        print("NO")