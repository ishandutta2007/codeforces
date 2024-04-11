vovel = 'aeiou'
odd = '13579'
s = input()
count = 0
for c in s:
    if c in vovel:
        count+=1
    elif c in odd:
        count+=1

print(count)