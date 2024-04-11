n=input()
text=raw_input()
ans=0
for i in range(n):
    if text[i]=='B':
        ans+=2**(i)
print ans