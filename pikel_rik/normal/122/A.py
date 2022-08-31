n = int(input())
flag = 0

def lucky(n):
    s = str(n)
    for i in s:
        if i != '4' and i != '7':
            return False
    return True

if lucky(n):
    print("YES")
    flag = 1
else:
    for i in range(4, n):
        if lucky(i) and n % i == 0:
            print("YES")
            flag = 1
            break

if flag == 0:
    print("NO")