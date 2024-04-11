x=int(input())
string=input()
i=0
for i in range(x-1):
    if string[i]>string[i+1]:
        print(string[:i]+string[i+1:])
        break
else:
    print(string[:-1])