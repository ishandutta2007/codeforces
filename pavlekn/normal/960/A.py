s = input()
if (s.count('a') > 0 and s.count("b") > 0 and (s.count("c") == s.count("b") or s.count("c") == s.count("a")) and s.rfind("a") < s.find("b") and s.rfind("b") < s.find("c")):
    print("YES")
else:
    print("NO")