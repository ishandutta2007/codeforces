input()
a=0
counter=0
for i,j in zip(input(),input()):
    a=j!=i!=a
    counter+=a
    a*=j
print(counter)