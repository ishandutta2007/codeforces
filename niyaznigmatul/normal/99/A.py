
s, t = raw_input().split(".")
print "GOTO Vasilisa." if s.endswith('9') else int(s) + 1 if int(t[0]) in range(5, 10) else s