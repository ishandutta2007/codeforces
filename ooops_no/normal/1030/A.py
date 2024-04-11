a=int(input())
x=[int(i)for i in input().split()]
for i in x:
    if i==1:
        print("HARD")
        break
else:
    print("EASY")