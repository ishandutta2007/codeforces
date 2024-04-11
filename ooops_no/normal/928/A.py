x=input()
n=int(input())
for i in range(n):
    s1=input()
    if len(s1) != len(x):
        continue
    for i in range(len(s1)):
        if s1[i].lower() != x[i].lower():
            if (x[i] == "0" and (s1[i] == "o" or s1[i] == "O"))  or ((x[i] == "o" or x[i] == "O")  and s1[i] == "0" ):
                continue
            elif x[i] in ['L', 'l', 'i', 'I', '1'] and s1[i] in ['L', 'l', 'i', 'I', '1']:
                continue
            else:
                break
    else:
        print("No")
        break
else:
    print("Yes")