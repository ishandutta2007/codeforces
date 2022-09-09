ch = raw_input().strip()

s = raw_input().strip()
mas = ["qwertyuiop", "asdfghjkl;", "zxcvbnm,./"]

news = ""
delta = 1
if (ch == "L"):
    delta = -1

for ch2 in s:
    for j in xrange(3):
        if (ch2 in mas[j]):
            news += mas[j][mas[j].index(ch2) - delta]

print(news)