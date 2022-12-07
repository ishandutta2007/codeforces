s = raw_input()

if s[1:].isupper() or len(s) == 1:
    if s[0].isupper():
        print s.lower()
    else:
        print s[0].upper() + s[1:].lower()
else:
    print s