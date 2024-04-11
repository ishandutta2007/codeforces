import sys
text = sys.stdin.readline().strip("\n").split(":")
h = int(text[0]) % 12
m = int(text[1])
print 360 / 12 * h + 360.0 / 12.0 / 60.0 * m, " ", 360 / 60 * m