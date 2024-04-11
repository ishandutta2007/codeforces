a=input()
if "1" in a:
    a=a[a.index("1"):]
    if a.count("0")>5:
        print("YES")
    else:
        print("NO")
else:
    print("NO")