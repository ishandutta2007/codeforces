s = raw_input().strip()
mas = map(int, s.split("+"))

mas.sort()
#print mas

ans = ""
for i in mas:
    ans += str(i) + "+"

print(ans[:-1])