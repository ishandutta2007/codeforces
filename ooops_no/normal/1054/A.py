x=[int(i)for i in input().split()]
floor=x[0]
floorEgor=x[1]
floorLift=x[2]
Ulist=x[3]
Ulift=x[4]
Uzakr=x[5]
lest=(abs(floor-floorEgor))*Ulist
lift=(abs(x[0]-x[2]))*Ulift+(x[5]*2)
lift+=x[5]+(abs(floor-floorEgor))*x[4]
if lift<=lest:
    print("YES")
else:
    print("NO")