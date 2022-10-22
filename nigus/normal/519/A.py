import math
import sys
w=0
b=0
for i in range(0,8):
    s=input()
    for j in s:
        if j=='Q':
            w+=9
        if j=='R':
            w+=5
        if j=='B':
            w+=3
        if j=='N':
            w+=3
        if j=='P':
            w+=1
        if j=='q':
            b+=9
        if j=='r':
            b+=5
        if j=='b':
            b+=3
        if j=='n':
            b+=3
        if j=='p':
            b+=1
if b==w:
    print("Draw")
if b>w:
    print("Black")
if w>b:
    print("White")