
n = int(raw_input())
a = map(int, raw_input().split())
a.sort()
print "YES" if sum(1 for i in range(len(a) - 1) if a[i] != a[i + 1] and a[i] * 2 > a[i + 1]) > 0 else "NO"