x = input()
result = eval(x)


def printchar(x):
    for i in range(x):
        print("+", end="")
    for i in range(48):
        print("+", end="")
    print(".", end="")
    for i in range(48):
        print("-", end="")
    for i in range(x):
        print("-", end="")
    print()

for c in str(result):
    printchar(int(c))