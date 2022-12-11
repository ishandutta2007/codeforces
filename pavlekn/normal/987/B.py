def main():
    x, y = map(int, input().split())
    if (x == y):
        print("=")
        return
    if (x == 1 and y != 1):
        print("<")
    elif (y == 1 and x != 1):
        print(">")
    elif (x < 1000 and y < 1000):
        if (x ** y > y ** x):
            print(">")
        elif (x ** y < y ** x):
            print("<")
        else:
            print("=")
    else:
        if (x > y):
            print("<")
        elif (y > x):
            print(">")
        else:
            print("=")
main()