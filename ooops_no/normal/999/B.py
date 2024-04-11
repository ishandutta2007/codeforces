x=int(input())
string=input()
for i in range(1,x+1):
    if x%i==0:
        string=string[:i][::-1]+string[i:]
print(string)