s=input()
lens=len(s)
cnt=0
for i in range(lens):
    for j in range(i,lens):
        str=s[i:j+1]
        if str!=str[::-1]:
            cnt=max(cnt,len(s[i:j+1]))
print(cnt)