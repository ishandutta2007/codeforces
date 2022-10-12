ls = sorted([int(s) for s in input().split()])

if ls[0] == ls[1] == ls[2] == ls[3] and ls[4] < ls[5]:
    print('Bear')
elif ls[1] == ls[2] == ls[3] == ls[4] and ls[0] < ls[5]:
    print('Bear')
elif ls[2] == ls[3] == ls[4] == ls[5] and ls[0] < ls[1]:
    print('Bear')
elif ls[0] == ls[1] == ls[2] == ls[3] and ls[4] >= ls[5]:
    print('Elephant')
elif ls[1] == ls[2] == ls[3] == ls[4] and ls[0] >= ls[5]:
    print('Elephant')
elif ls[2] == ls[3] == ls[4] == ls[5] and ls[0] >= ls[1]:
    print('Elephant')
else:
    print('Alien')