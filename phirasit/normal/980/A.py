inp = input().strip()

print ("YES" if inp.count("o") == 0 or inp.count("-") % inp.count("o") == 0 else "NO")