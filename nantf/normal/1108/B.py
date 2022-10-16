n = int(input())

s = raw_input().split()

i = 0

mx = 0

while i < n:
    mx = max (mx, int(s[i]))
    i += 1

i = 0

mx2 = 0

vis = [0] * 11111

while i < n:
    if (mx % int(s[i]) != 0) or (vis[int(s[i])] == 1):
        mx2 = max(mx2, int(s[i]))
    else:
        vis[int(s[i])] = 1
    i += 1

print "%d %d" % (mx, mx2)