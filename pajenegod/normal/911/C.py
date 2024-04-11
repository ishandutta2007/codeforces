import sys
k1,k2,k3 = [int(x) for x in input().split()]
def is_div(a,b):
    return a==((a//b)*b)

def always_lit(x1,x2,k1,k2,k3):
    for i in range(200):
        if not is_div(i-x1,k1) and not is_div(i-x2,k2) and not is_div(i,k3):
            return False
    return True

for x1 in range(-200,1):
    for x2 in range(x1,1):
        if always_lit(x1,x2,k1,k2,k3):
            print('YES')
            sys.exit()

print('NO')