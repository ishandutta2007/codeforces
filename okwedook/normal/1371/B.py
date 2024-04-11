
test = int(input())
temp = test
my_list = []

def print_func():
    for n in my_list:
        print(n)

def append_func(number):
    string = (number)
    my_list.append(string)

while (test != 0):
    n, r  = [int(x) for x in input().split()] # Taking the input for n and r
    k = 0                                     
    l = 1
    if ( n <= l):
        k = 1
        append_func(k)
        test -= 1
        continue
    if (n <= r):                              # Removing the same cases when r increases beyond the n or becomes equal to n
        r = n - 1
        k = 1                                 # Increasing the number for one as the similiar shapes are declined but one case has to be included
    
    k = int(k + ((l + r) * (r - l + 1)) // 2)       # Using the formula as a + (a + 1) + (a + 2) ... b = ( (a + b) * (b - a + 1) ) / 2
    append_func(k)
    test -= 1

print_func()