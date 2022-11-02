x=int(input())
for i in range(x):
    string=list(map(str,input()))
    if string.count(string[0])==len(string):
        print(-1)
        continue
    counter=0
    while string==string[::-1]:
        while string[counter]==string[counter+1] and counter<len(string):
            counter+=1
        string[counter],string[counter+1]=string[counter+1],string[counter]
    for i in string:
        print(i,end="")
    print()