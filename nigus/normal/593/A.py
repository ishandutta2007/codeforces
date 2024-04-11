import math
from decimal import *
import sys
from fractions import Fraction


n=int(input())

S=set()
M=dict()
ma=0
alf = "abcdefghijklmnopqrstuvwxyz"
for c in range(0,n):
    s=input()
    L=len(s)
    co=len(set(s))
    if co == 1:
        ch=s[0]
        for j in alf:
            if ch+j not in S:
                S.add(ch+j)
                M[ch+j] = L
            else:
                M[ch+j] += L
            if ch != j:
                if j+ch not in S:
                    S.add(j+ch)
                    M[j+ch] = L
                else:
                    M[j+ch] += L
    if co == 2:
        ch1 = s[0]
        for j in range(0,L):
            if s[j] != ch1:
                ch2 = s[j]
        if ch1+ch2 not in S:
            S.add(ch1+ch2)
            M[ch1+ch2] = L
        else:
            M[ch1+ch2] += L
        if ch2+ch1 not in S:
            S.add(ch2+ch1)
            M[ch2+ch1] = L
        else:
            M[ch2+ch1] += L
for i in alf:
    for j in alf:
        if i+j in S:
            if M[i+j]>ma:
                ma=M[i+j]
print(ma)