s=input()
if s.count('at')>=1:
    for i in range(2,len(s)):
        if s[i-1:i+1]=='at':
            s=s[:i-1]+'@'+s[i+1:]
            break
if 'dot'in s:
    s=s[:1]+s[1:-1].replace('dot','.')+s[-1:]
print(s)