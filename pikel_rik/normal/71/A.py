n = int(input())

l = [str(input()) for i in range(n)]

for s in l:
    temp = ""
    if (len(s) > 10):
        temp = s[0] + str(len(s)-2) + s[len(s)-1];
    else:
        temp = s;
    print(temp);