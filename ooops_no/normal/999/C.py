a,b=map(int,input().split())
string=input()
letter=97
while b>0:
    counter=string.count(chr(letter))
    string=string.replace(chr(letter),"",min(counter,b))
    if b<=counter:
        break
    b-=counter
    letter+=1
print(string)