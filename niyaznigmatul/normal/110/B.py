n = int(raw_input())
s = ""
for i in range(n):
    s += chr(ord('a') + i % 4)
print s