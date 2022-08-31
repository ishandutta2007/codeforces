n = int(input())
m = n+1

def isDistinct(m):
    s = str(m)
    if s[0] in s[1:]:
        return False
    if s[1] in s[2:]:
        return False
    if s[2] == s[3]:
        return False
    return True

while isDistinct(m) == False:
    m += 1

print(m)