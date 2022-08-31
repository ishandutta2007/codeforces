#!/usr/bin/env python3
# -*- coding: utf-8 -*-
__author__ = 'cnyali_lk'
import sys
def query(s,t,v):
    if len(s)==0 or len(t)==0:
        return 0
    print(len(s))
    for i in s:
        print(i,end=' ')
    print()
    print(len(t))
    for i in t:
        print(i,end=' ')
    print()
    print(v)
    sys.stdout.flush()
    return int(input())

n=int(input())
d=[0]*(n+1)
for i in range(2,n+1):
    d[i]=query(list(range(2,i))+list(range(i+1,n+1)),[1],i)

v=list(range(2,n+1))
v.sort(key=lambda x:d[x])
nofa=[]
ans=[]
for i in v:
    if len(nofa):
        for t in range(query([1],nofa,i)):
            l,r=1,len(nofa)
            while l<=r:
                mid=(l+r)//2
                if query([1],nofa[:mid],i)>0:
                    r=mid-1
                else:
                    l=mid+1
            w=nofa[r]
            nofa.remove(w)
            ans.append((w,i))
    nofa.append(i)
for i in nofa:
    ans.append((i,1))
print("ANSWER")
for i in ans:
    print(i[0],i[1])