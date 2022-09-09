n, m = map(int, raw_input().strip().split())
masx = map(int, raw_input().strip().split())
masn = masx[:]
min_ans, max_ans = 0, 0
count_null = 0

for i in xrange(n):
    masx.sort()
    masx.reverse()
    masn.sort()
    masn.reverse()
    #print mas
    max_ans += masx[0]
    masx[0] -= 1
    min_ans += masn[m - count_null - 1]
    masn[m - count_null - 1] -= 1
    if(masn[m - count_null - 1] == 0):
        count_null += 1

print max_ans, min_ans