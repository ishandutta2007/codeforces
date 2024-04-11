exec("res = " + input())
print("+" * 48)
for c in str(res):
  print("+" * int(c) + ".")
  print("-" * int(c))