
n = int(raw_input())
a = []
for i in range(n):
    a.append(int(raw_input()))
s = set(a)
if (len(s) == 1):
    print "Exemplary pages."
elif len(s) > 3 or (max(a) - min(a)) % 2 == 1 or a.count((max(a) + min(a)) // 2) + 2 != len(a):
    print "Unrecoverable configuration."
else:
    print "%d ml. from cup #%d to cup #%d."%((max(a) - min(a)) // 2, a.index(min(a)) + 1, a.index(max(a)) + 1)