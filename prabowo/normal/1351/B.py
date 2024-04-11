for tc in range(int(input())):
    a1, b1 = input().split()
    a2, b2 = input().split()

    if a1 == a2 and int(a1) == int(b1) + int(b2):
        print('Yes')
    elif a1 == b2 and int(a1) == int(b1) + int(a2):
        print('Yes')
    elif b1 == a2 and int(b1) == int(a1) + int(b2):
        print('Yes')
    elif b1 == b2 and int(b1) == int(a1) + int(a2):
        print('Yes')
    else:
        print('No')