arr = raw_input()
num = (int(arr[0]) - int('0')) * 10000 + (int(arr[2]) - int('0')) * 1000 + (int(arr[4]) - int('0')) * 100 + (int(arr[3]) - int('0')) * 10 + (int(arr[1]) - int('0'))
num = num ** 5
num %= 100000
if num == 0:
    print "00000"
else:
    x = 0
    tmp = num
    while tmp:
        x += 1
        tmp /= 10
    x = 5 - x
    ans = ""
    while x:
        x -= 1
        ans += "0"
    ans += str(num)
    print ans