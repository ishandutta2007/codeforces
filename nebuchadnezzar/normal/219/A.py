import string
str_eng = string.ascii_lowercase
k = input()
s = raw_input()
mas = [0] * 26
for ch in s:
    mas[str_eng.index(ch)] += 1

ans = ""
for i in xrange(26):
    if(mas[i] % k == 0):
        ans += (str_eng[i]) * (mas[i] / k)
    else:
        ans = "-1"  
        break

if(ans != "-1"):
    ans = ans * k
print ans