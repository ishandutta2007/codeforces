x=int(input())
string=input()
last=0
new=0
maximum=0
if string.count("G")==0:
    print(0)
else:
    for i in string:
        if i=="G":
            new+=1
        else:
            maximum=max(maximum,new+last)
            last=new
            new=0
    
    if string.count("S")==1:
        print(x-1)
    elif string.count("S")==0:
        print(x)
    elif maximum==0:
        print(x-string.count("S"))
    else:
        maximum=max(maximum+1,new+last+1)
        if maximum>=string.count("G"):
            print(string.count("G"))
        else:
            print(maximum)