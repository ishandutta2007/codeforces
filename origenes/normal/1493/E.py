n = int(input())
l = input()
r = input()
if l[0] != r[0]:
    print('1' * n)
elif r[-1] == '1' or int(l, 2) + 2 > int(r, 2):
    print(r)
else:
    print("{0:b}".format(int(r, 2) + 1))