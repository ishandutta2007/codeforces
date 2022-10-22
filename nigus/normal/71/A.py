import math
import sys

n=int(input())

for i in range(0,n):

    s = input()
    l = len(s)
    if l > 10:

        t = ""
        t+=s[0]
        t+=str(l-2)
        t+=s[l-1]
        print(t)
        
    else:
        print(s)