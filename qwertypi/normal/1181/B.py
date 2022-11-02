import math
n = int(input())
k = input()

def st(s):
    if(s == ''):
        return 0
    return int(s)
def cal(pos):
    if(k[pos] == '0'):
        return 1 << 400000
    return st(k[:pos]) + st(k[pos:])


mid_L = (n + 1) // 2
mid_R = n // 2
sum = -1;
while(k[mid_L] == k[mid_R] == '0'):
    mid_L-=1
    mid_R+=1

sum = min(cal(mid_L), cal(mid_R))
print(sum)