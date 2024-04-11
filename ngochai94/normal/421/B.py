x=raw_input()
let='AHIMOTUVWXY'
ans=True
for i in x:
    if i not in let:
        ans=False
        break
if x!=x[::-1]:
    ans=False
if ans:
    print 'YES' 
else:
    print 'NO'