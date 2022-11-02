x=list(map(int,input().split()))
kol_vo=x[0]
friends=x[1]
had=x[2]
new=x[3]
if (new+had)%friends!=0:
    i=(new+had)//friends+1
else:
    i=(new+had)//friends
if kol_vo<friends*i:
    print(-1)
else:
    print(i)