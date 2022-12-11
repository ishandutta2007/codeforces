n = int(input())
s = input()
if (s == '0'):
    print(0)
else:
    d = s.count("0")
    print('1' + d * ("0"))