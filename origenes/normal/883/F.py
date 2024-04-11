n = int(input())
dict_ch={}
for i in range(n):
    ch = input()
    if 'u' in ch:
        ch = ch.replace('u','oo')
    while 'kh' in ch:
        ch = ch.replace('kh','h')
    if ch not in dict_ch:
        dict_ch.update({ch:1})
print(len(dict_ch))