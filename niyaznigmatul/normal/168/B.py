import re
wasBuf = 0
buf = ""
while True:
    try:
        s = raw_input()
    except EOFError:
        break
    ok = False
    i = 0
    while i < len(s) and s[i] == ' ':
        i += 1
    if i < len(s) and s[i] == '#':
        if wasBuf == 1:
            print buf
            wasBuf = 0
            buf = ""
        print s
    else:
        for i in range(len(s)):
            if s[i] != ' ':
                buf += s[i]
        wasBuf = 1
#    print "buf = %s"%[buf]
if wasBuf == 1:
    print buf