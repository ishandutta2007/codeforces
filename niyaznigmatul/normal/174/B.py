s = raw_input().split(".")
if len(s) > 1 and len(s[0]) in range(1, 9) and len(s[-1]) in range(1, 4) and (len(s) <= 2 or (max(map(len, s[1:-1])) <= 11 and min(map(len, s[1:-1])) >= 2)):
    ans = []
    current = s[0]
    for x in s[1:-1]:
        pref = max(1, len(x) - 8)
        current += "."
        current += x[:pref]
        ans.append(current)
        current = x[pref:]
    current += "."
    current += s[-1]
    ans.append(current)
    print "YES"
    for x in ans:
        print x
else:
    print "NO"