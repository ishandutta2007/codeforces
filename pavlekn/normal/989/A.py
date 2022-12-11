s = input()
if (s.count("BAC") > 0 or s.count("ABC") > 0 or s.count("ACB") > 0 or s.count("BCA") > 0 or s.count("CBA") > 0 or s.count("CAB") > 0):
    print("Yes")
else:
    print("No")