def function(s):
    lens=len(s)
    if lens%2:
        return s
    return sorted([function(s[:lens//2]),function(s[lens//2:])])
if function(input())==function(input()):
    print("YES")
else:
    print("NO")