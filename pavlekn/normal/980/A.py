s = input()
print("YES" if (s.count("o") == 0 or s.count("-") % s.count("o") == 0) else "NO")