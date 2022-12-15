st=raw_input()
k=input()
dic={}
s='abcdefghijklmnopqrstuvwxyz'
val=map(int,raw_input().split())
ma=max(val)
for i in range(26):
    dic[s[i]]=val[i]
ans=ma*k*(2*len(st)+1+k)/2
for i in range(len(st)):
    ans+=dic[st[i]]*(i+1)
print ans