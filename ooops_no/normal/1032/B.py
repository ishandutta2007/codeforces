string=input()
dl=len(string)
if dl%20==0:
    kol_vo_str=dl//20
else:
    kol_vo_str=dl//20+1
dl_str=dl//kol_vo_str
if dl-dl_str*kol_vo_str==0:
    counter1=0
    counter2=dl_str
    print(kol_vo_str,dl_str)
    for i in range(kol_vo_str):
        print(string[counter1:counter2])
        counter1+=dl_str
        counter2+=dl_str
else:
    dl_str+=1
    counter1=0
    counter2=dl_str
    print(kol_vo_str,dl_str)
    for i in range(kol_vo_str):
        if dl-dl_str*kol_vo_str!=0:
            print('*',end='')
            dl+=1
            print(string[counter1:counter2-1])
            counter1+=dl_str-1
            counter2+=dl_str-1
        else:
            print(string[counter1:counter2])
            counter1+=dl_str
            counter2+=dl_str