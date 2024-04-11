x=input()
seven_counter=0
four_counter=0
for i in x:
    if i =="4":
        four_counter+=1
    elif i=="7":
        seven_counter+=1
if seven_counter==0 and four_counter==0:
    print(-1)
elif seven_counter>four_counter:
    print(7)
else:
    print(4)