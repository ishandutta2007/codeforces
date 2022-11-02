n,k=map(int,input().split())
string=input()
counter=0
for i in range(1,len(string)):
    if string[:i]==string[-i:]:
        counter=i
print(string+string[counter:]*(k-1))